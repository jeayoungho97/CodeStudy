#include <iostream>
#include <string>
#include <algorithm>

int main() {
  while (true) {
    std::string input;
    std::cin >> input;
    if (input == "0") break;

    std::string temp = input;
    std::reverse(input.begin(), input.end());

    if (temp == input) std::cout << "yes\n";
    else std::cout << "no\n";
  }

  return 0;
}