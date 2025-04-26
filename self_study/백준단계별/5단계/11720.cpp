#include <iostream>
#include <string>

int main() {
  int N;
  std::cin >> N;
  std::string s;
  std::cin >> s;

  int result = 0;
  for (char ch : s) {
    result += ch - '0';
  }

  std::cout << result << '\n';
  return 0;
}