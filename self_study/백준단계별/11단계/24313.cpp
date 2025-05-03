#include <iostream>

int main() {
  int a1, a0, c, n0;
  std::cin >> a1 >> a0 >> c >> n0;
  int result = 0;

  if (c > a1 && (a0 / (c - a1)) <= n0) result = 1;
  if (c == a1 && a0 <= 0) result = 1;

  std::cout << result << '\n';
  return 0;
}