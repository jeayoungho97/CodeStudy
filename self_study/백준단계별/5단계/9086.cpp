#include <iostream>
#include <string>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    std::string S;
    std::cin >> S;

    std::cout << S[0] << S[S.length() - 1] << '\n';
  }
  return 0;
}