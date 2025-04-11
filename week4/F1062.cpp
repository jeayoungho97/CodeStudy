#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>

int n, k;
int result = 0;
std::vector<std::array<bool, 26>> words_bit;

void go(std::array<bool, 26> word_bit, int start) {
  int count = 0;
  for (int i = 0; i < 26; ++i) {
    if (word_bit[i]) ++count;
  }

  if (count == k) {
    int okay = 0;
    int size = words_bit.size();
    for (int i = 0; i < size; ++i) {
      bool flag  = false;
      for (int j = 0; j < 26; ++j) {
        if(words_bit[i][j] && !word_bit[j]) {
          flag = true;
          break;
        }
      }
      if(flag) continue;
      ++okay;
    }
    result = std::max(result, okay);
  }

  for (int i = start; i < 26; ++i) {
    if (word_bit[i] == false) {
      word_bit[i] = true;
      go(word_bit, i + 1);
      word_bit[i] = false;
    }
  }
}

int main() {
  std::cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    
    std::array<bool, 26> word_bit = {};
    for (int j = 0; j < 26; ++j) {
      if (std::find(str.begin(), str.end(), j + 'a') != str.end()) {
        word_bit[j] = true;
      }
    }
    words_bit.push_back(word_bit);
  }

  std::string antic_str = "antic";
  std::array<bool,26> antic_bit = {};
  for (int i = 0; i < 26; ++i) {
    if (std::find(antic_str.begin(), antic_str.end(), i + 'a') != antic_str.end()) {
      antic_bit[i] = true;
    }
  }

  go(antic_bit, 0);
  std::cout << result << '\n';

  return 0;
}