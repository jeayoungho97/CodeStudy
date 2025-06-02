#include <iostream>
#include <string>

int main() {
  std::string a, b;
  int c;
  std::cin >> a >> b >> c;
  std::string ret = a + b;

  std::cout << std::stoi(a) + std::stoi(b) - c << '\n';
  std::cout << std::stoi(ret) - c << '\n';

  return 0;
}