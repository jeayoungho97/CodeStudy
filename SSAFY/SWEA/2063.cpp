#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  std::sort(arr.begin(), arr.end());

  std::cout << arr[(n - 1) / 2] << '\n';

  return 0;
}