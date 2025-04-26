#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;

  std::reverse(s1.begin(), s1.end());
  std::reverse(s2.begin(), s2.end());

  std::cout << std::max(s1, s2) << '\n';
  return 0;
}