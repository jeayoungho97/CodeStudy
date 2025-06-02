#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string temp;
    std::cin >> temp;

    int ret = 0, cnt = 0;
    for (char ch : temp) {
      if (ch == 'O') {
        ++cnt;
        ret += cnt;
      }
      else {
        cnt = 0;
      }
    }

    std::cout << ret << '\n';
  }

  return 0;
}