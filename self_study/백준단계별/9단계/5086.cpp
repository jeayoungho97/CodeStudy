#include <iostream>

int main() {
  while (true) {
    int a, b;
    std::cin >> a >> b;
    if (a == 0 && b == 0) break;
    if (a % b == 0) std::cout << "multiple" << '\n';
    else if (b % a == 0) std::cout << "factor" << '\n';
    else std::cout << "neither" << '\n';
  }

  return 0;
}