#include <iostream>

constexpr int kMaxSize = 101;
int n, l;
int result = 0;
int board[kMaxSize][kMaxSize];

bool check_row(int row) {
  bool visited[kMaxSize][kMaxSize] = {};

  for (int col = 0; col < n - 1; ++col) {
    int diff = board[row][col] - board[row][col + 1];

    if (std::abs(diff) >= 2) return false;

    if (diff == 1) {
      if (col + l >= n || visited[row][col + 1]) return false;
      else {
        for (int i = 1; i <= l; ++i) {
          if (board[row][col + i] != board[row][col + 1]) return false;
          if (visited[row][col + i]) return false;
          visited[row][col + i] = true;
        }
      }
    }

    if (diff == -1) {
      if (col - (l - 1) < 0 || visited[row][col]) return false;
      else {
        for (int i = 0; i < l; ++i) {
          if (board[row][col - i] != board[row][col]) return false;
          if (visited[row][col - i]) return false;
          visited[row][col - i] = true;
        }
      }
    }
  }

  return true;
}

bool check_col(int col) {
  bool visited[kMaxSize][kMaxSize] = {};

  for (int row = 0; row < n - 1; ++row) {
    int diff = board[row][col] - board[row + 1][col];

    if (std::abs(diff) >= 2) return false;

    if (diff == 1) {
      if (row + l >= n || visited[row + 1][col]) return false;
      else {
        for (int i = 1; i <= l; ++i) {
          if (board[row + i][col] != board[row + 1][col]) return false;
          if (visited[row + i][col]) return false;
          visited[row + i][col] = true;
        }
      }
    }

    if (diff == -1) {
      if (row - (l - 1) < 0 || visited[row][col]) return false;
      else {
        for (int i = 0; i < l; ++i) {
          if (board[row - i][col] != board[row][col]) return false;
          if (visited[row - i][col]) return false;
          visited[row - i][col] = true;
        }
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
    if(check_row(i)) ++result;
    if(check_col(i)) ++result;
  }

  std::cout << result << '\n';
  return 0;
}