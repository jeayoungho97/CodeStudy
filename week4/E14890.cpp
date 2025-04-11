#include <iostream>
#include <cmath>

constexpr int kMaxSize = 101;

int n, l;
int result = 0;
int board[kMaxSize][kMaxSize];

bool CheckLine(int index, bool row_mode) {
  bool visited[kMaxSize] = {};

  for (int i = 0; i < n - 1; ++i) {
    int curr = row_mode ? board[index][i] : board[i][index];
    int next = row_mode ? board[index][i + 1] : board[i + 1][index];
    int diff = curr - next;

    if (std::abs(diff) >= 2) return false;

    if (diff == 1) {
      for (int j = 1; j <= l; ++j) {
        int ni = i + j;
        if (ni >= n) return false;

        int h = row_mode ? board[index][ni] : board[ni][index];
        if (h != next || visited[ni]) return false;
        visited[ni] = true;
      }
    }

    if (diff == -1) {
      for (int j = 0; j < l; ++j) {
        int ni = i - j;
        if (ni < 0) return false;

        int h = row_mode ? board[index][ni] : board[ni][index];
        if ( h != curr || visited[ni]) return false;
        visited[ni] = true;
      }
    }
  }

  return true;
}

int main() {
  std::cin >> n >> l;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> board[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    if(CheckLine(i, true)) ++result;
    if(CheckLine(i, false)) ++result;
  }

  std::cout << result << '\n';
  return 0;
}