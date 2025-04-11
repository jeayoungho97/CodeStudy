#include <iostream>
#include <algorithm>

constexpr int kMaxSize = 101;
int n, l;
int result = 0;
int board[kMaxSize][kMaxSize];
int boardTranspose[kMaxSize][kMaxSize];

void Check(int board[kMaxSize][kMaxSize]) {
  for (int i = 0; i < n; ++i) {
    int count = 1;
    int j;
    for (j = 0; j < n - 1; ++j) {
      int diff = board[i][j] - board[i][j + 1];
      if (diff == 0) {
        ++count;
      }
      else if (diff == 1 && count >= 0) {
        count = -l + 1;
      }
      else if (diff == -1 && count >= l) {
        count = 1;
      }
      else break;

    }
    if (j == n - 1 && count >= 0) ++result;
  }
}

int main() {
  std::cin >> n >> l;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> board[i][j];
      boardTranspose[j][i] = board[i][j];
    }
  }

  Check(board); Check(boardTranspose);
  std::cout << result << '\n';
  return 0;
}