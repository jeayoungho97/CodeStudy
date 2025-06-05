#include <iostream>

const int INF = 1e9;
int n, k, summer[104], dp[10004];

int main() {
  std::fill(dp, dp + 10004, INF);
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> summer[i];
  }

  dp[0] = 0;

  for (int i = 0; i <= k; ++i) {

    if (dp[i] == INF) continue;

    for (int j = 0; j < n; ++j) {
      int next = i + summer[j];
      if (next > k) continue;
      dp[next] = std::min(dp[next], 1 + dp[i]);
    }
  }

  if (dp[k] == INF) std::cout << -1 << '\n';
  else std::cout << dp[k] << '\n';

  return 0;
}