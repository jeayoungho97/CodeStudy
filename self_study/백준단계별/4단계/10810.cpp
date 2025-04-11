#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> basket(n, 0);

  for (int t = 0; t < m; ++t) {
    int left, right, value;
    std::cin >> left >> right >> value;

    for (int i = left - 1; i < right; ++i) {
      basket[i] = value;
    }
  }

  for (int val : basket) {
    std::cout << val << " ";
  }
  std::cout << '\n';

  return 0;
}