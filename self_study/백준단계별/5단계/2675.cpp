#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int size = s.size();
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << s[i];
      }
    }
    std::cout << '\n';
  }

  return 0;
}