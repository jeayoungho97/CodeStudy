#include <iostream>
#include <cstring>

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};
int n, m, map[51][51], dp[51][51];
bool visited[51][51];

int go(int i, int j) {

  int &ret = dp[i][j];
  if (ret != -1) return ret;
  
  ret = 0;
  for (int dir = 0; dir < 4; ++dir) {
    int ni = i + map[i][j] * di[dir];
    int nj = j + map[i][j] * dj[dir];

    if (ni < 0 || nj < 0 || ni >= n || nj >= m || map[ni][nj] == 0) {
      continue;
    }

    if (visited[ni][nj]) {
      std::cout << -1 << '\n';
      exit(0);
    }

    visited[ni][nj] = true;
    ret = std::max(ret, 1 + go(ni, nj));
    visited[ni][nj] = false;
  }
  return ret;
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      std::cin >> ch;
      if (ch == 'H') map[i][j] = 0;
      else map[i][j] = ch - '0';
    }
  }
  std::memset(dp, -1, sizeof(dp));

  visited[0][0] = true;
  std::cout << go(0, 0) + 1 << '\n';
  return 0;
}