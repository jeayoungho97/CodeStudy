#include <iostream>

int main() {
  bool visited[43] = {};
  int result = 0;
  for (int i = 0; i < 10; ++i) {
    int a;
    std::cin >> a;
    visited[a % 42] = true;
  }

  for (bool a : visited) {
    if (a) ++result;
  }

  std::cout << result << '\n';

  return 0;
}