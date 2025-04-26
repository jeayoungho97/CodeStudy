#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  int i;
  std::cin >> i;

  std::cout << S[i - 1] << '\n';

  return 0;
}