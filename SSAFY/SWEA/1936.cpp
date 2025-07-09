#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  char result = (a > b) ? 'A' : 'B';
  if (a - b == 2) result = 'B';
  if (b - a == 2) result = 'A';

  std::cout << result << '\n';
  return 0;
}