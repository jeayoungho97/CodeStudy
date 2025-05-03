#include <iostream>

int main() {
  long long n;
  std::cin >> n;
  long long result = ((n - 2) * (n - 1) * (2 * n - 3) / 6 + (n - 2) * (n - 1) / 2 ) / 2;
  std::cout << result << '\n' << 3 << '\n';
  return 0;
}