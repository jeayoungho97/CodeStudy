#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string str;
  std::vector<char> col[15];

  for (int i = 0; i < 5; ++i) {
    std::cin >> str;
    for (int j = 0; j < str.length(); ++j) {
      col[j].push_back(str[j]);
    }
  }
  for (int i = 0; i < 15; ++i) {
    if (!col[i].empty()) {
      for (char ch : col[i]) {
        std::cout << ch;
      }
    }
  }
  std::cout << '\n';
  
  return 0;
}