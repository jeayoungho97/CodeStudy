#include <iostream>
#include <string>

int main() {
  std::string str, bomb;
  std::cin >> str >> bomb;

  std::string result = "";

  for (char ch : str) {
    result.push_back(ch);

    if (result.size() >= bomb.size()) {
      int r_size = result.size();
      int b_size = bomb.size();
      bool is_bomb = true;

      for (int i = 0; i < b_size; ++i) {
        if (result[r_size - b_size + i] != bomb[i]) {
          is_bomb = false;
          break;
        }
      }
      if (is_bomb) {
        for (int i = 0; i < b_size; ++i) {
          result.pop_back();
        }
      }
    }
  }

  if (result.empty()) {
    std::cout << "FRULA\n";
  }
  else {
    std::cout << result << '\n';
  }

  return 0;
}