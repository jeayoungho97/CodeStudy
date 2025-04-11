#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  int* basket = new int[n]();
  for (int temp = 0; temp < m; ++temp) {
    int i, j, k;
    std::cin >> i >> j >> k;
    for (int a = i - 1; a < j; ++a) {
      basket[a] = k;
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << basket[i] << " ";
  }
  std::cout << '\n';

  delete[] basket;
  basket = nullptr;
  
  return 0;
}