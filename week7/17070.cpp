#include <iostream>
#include <cstring>

int n, map[16][16], dp[16][16][3];

int go(int i, int j, int dir) {
  if (i >= n || j >= n || map[i][j] == 1) return 0;
  if (i == n - 1 && j == n - 1) return 1;

  int &ret = dp[i][j][dir];
  if (ret != -1) return ret;
  ret = 0;

  if (dir == 0 || dir == 1) {
    if (j + 1 < n && map[i][j + 1] == 0) {
      ret += go(i, j + 1, 0);
    }
  }

  if (dir == 1 || dir == 2) {
    if (i + 1 < n && map[i + 1][j] == 0) {
      ret += go(i + 1, j, 2);
    }
  }

  if (i < n - 1 && j < n - 1) {
    if (map[i + 1][j] == 0 && map[i][j + 1] == 0 && map[i + 1][j + 1] == 0) {
      ret += go(i + 1, j + 1, 1);
    }
  }

  return ret;
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }

  std::memset(dp, -1, sizeof(dp));

  std::cout << go(0, 1, 0) << '\n';

  return 0;
}