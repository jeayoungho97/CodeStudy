#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string str, bomba;
  std::cin >> str >> bomba;

  size_t n = bomba.size();
  std::vector<char> result;

  for (char ch : str) {
    result.push_back(ch);

    if (result.size() >= n) {
      bool is_bomba = true;
      for (size_t i = 0; i < n; ++i) {
        if (result[result.size() - n + i] != bomba[i]) {
          is_bomba = false;
          break;
        }
      }

      if (is_bomba) {
        for (int i = 0; i < n; ++i) {
          result.pop_back();
        }
      }
    }
  }

  if (result.empty()) {
    std::cout << "FRULA\n";
  }
  else {
    for (char ch : result) {
      std::cout << ch;
    }
    std::cout << '\n';
  }
  return 0;
}