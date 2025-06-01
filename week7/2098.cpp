#include <iostream>
#include <algorithm>
#include <cstring>

const int INF = 1e9;
int n, cost[16][16], dp[16][1 << 16];

int tsp(int cur, int visited) {
  if (visited == (1 << n) - 1) {
    if (cost[cur][0] == 0) return INF;
    return cost[cur][0];
  }

  int &ret = dp[cur][visited];
  if (ret != -1) return ret;

  ret = INF;
  for (int next = 0; next < n; ++next) {
    if (((1 << next) & visited) == 0 && cost[cur][next] != 0) {
      ret = std::min(ret, cost[cur][next] + tsp(next, visited | (1 << next)));
    }
  }

  return ret;
}

int main() {
  std::memset(dp, -1, sizeof(dp));
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> cost[i][j];
    }
  }

  std::cout << tsp(0, 1) << '\n';

  return 0;
}