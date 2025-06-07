#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> input(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> input[i];
  }
  std::sort(input.begin(), input.end());

  for (int i = 0; i < n; ++i) {
    std::cout << input[i] << '\n';
  }

  return 0;
}