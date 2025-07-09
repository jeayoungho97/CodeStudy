#include <iostream>
#include <string>

int main() {
  std::string n;
  std::cin >> n;

  int result = 0;
  for (int i = 0; i < n.size(); ++i) {
    result += n[i] - '0';
  }

  std::cout << result << '\n';
  return 0;
}