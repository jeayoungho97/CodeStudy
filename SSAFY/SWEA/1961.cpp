#include <iostream>
#include <vector>
#define vv std::vector<std::vector<int>> 

vv rotate(const vv &arr) {
  int row = arr.size();
  int col = arr[0].size();
  vv result(col, std::vector<int>(row));
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      result[j][col - 1 - i] = arr[i][j];
    }
  }
  return result;
}

int main() {
  int t;
  std::cin >> t;

  for (int test_case = 1; test_case <= t; ++test_case) {
    int n;
    std::cin >> n;

    vv arr;

    for (int i = 0; i < n; ++i) {
      std::vector<int> temp(n);
      for (int j = 0; j < n; ++j) {
        std::cin >> temp[j];
      }
      arr.push_back(temp);
    }

    vv arr_90 = rotate(arr);
    vv arr_180 = rotate(arr_90);
    vv arr_270 = rotate(arr_180);

    std::cout << '#' << test_case << '\n';

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << arr_90[i][j];
      }
      std::cout << ' ';
      for (int j = 0; j < n; ++j) {
        std::cout << arr_180[i][j];
      }
      std::cout << ' ';
      for (int j = 0; j < n; ++j) {
        std::cout << arr_270[i][j];
      }
      std::cout << '\n';
    }


  }
  return 0;
}