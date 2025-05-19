#include <iostream>
#include <algorithm>
#include <string>

int n, m, result = 99;
char map[51][51];
std::string temp = "WBWBWBWB";

int check(int i, int j) {
  int sum = 0;
  for (int row = i; row < i + 8; ++row) {
    for (int col = j; col < j + 8; ++col) {
      if (map[row][col] != temp[col - j]) {
        ++sum;
      }
    }
    std::reverse(temp.begin(), temp.end());
  }
  return std::min(sum, 64 - sum);
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i <= n - 8; ++i) {
    for (int j = 0; j <= m - 8; ++j) {
      result = std::min(check(i, j), result);
    }
  }

  std::cout << result << '\n';

  return 0;
}