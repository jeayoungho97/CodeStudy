#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  if (a + b + c != 180) std::cout << "Error\n";
  else {
    if (a == 60 && b == 60 && c == 60) std::cout << "Equilateral\n";
    else if (a == b || b == c || c == a) std::cout << "Isosceles\n";
    else std::cout << "Scalene\n";
  }

  return 0;
}