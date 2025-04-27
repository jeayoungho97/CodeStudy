#include <iostream>

int main() {
  int max = 0;
  std::pair<int, int> index;
  
  int arr[9][9];
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      std::cin >> arr[i][j];
      if (arr[i][j] > max) {
        max = arr[i][j];
        index = std::pair(i, j);
      }
    }
  }

  std::cout << max << '\n';
  std::cout << index.first + 1 << ' ' << index.second + 1 << '\n';
  return 0;
}