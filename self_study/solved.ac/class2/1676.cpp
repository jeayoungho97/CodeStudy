#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int sum = 0;
  while (n != 0) {
    sum += n / 5;
    n /= 5;
  }

  std::cout << sum << '\n';
  return 0;
}