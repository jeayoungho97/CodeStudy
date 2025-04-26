#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  std::string s;
  int result = 0;
  while (std::cin >> s) {
    ++result;
  }
  std::cout << result << '\n';

  return 0;
}