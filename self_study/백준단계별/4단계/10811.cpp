#include <iostream>
#include <algorithm>

int main() {
  int N, M;
  std::cin >> N >> M;

  int* basket = new int[N];
  for (int i = 0; i < N; ++i) {
    basket[i] = i + 1;
  }

  while (M--) {
    int i, j;
    std::cin >> i >> j;
    std::reverse(basket + i - 1, basket + j);
  }

  for (int i = 0; i < N; ++i) {
    std::cout << basket[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}