#include <iostream>
#include <string>

std::string str;

void erase_word(std::string word) {
  size_t pos;
  while ((pos = str.find(word)) != std::string::npos) {
    str.erase(pos, word.length());
  }
}

int main() {
  std::cin >> str;
  erase_word("pi");
  erase_word("ka");
  erase_word("chu");
  if (str.empty()) {
    std::cout << "YES\n";
  }
  else {
    std::cout << "NO\n";
  }
  return 0;
}