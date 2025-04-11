#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

int n, k;
std::vector<std::array<bool, 26>> words_bit;

int CountReadable(const std::array<bool, 26> known) {
  int count = 0;
  for (const auto& word : words_bit) {
    bool readable = true;
    for (int i = 0; i < 26; ++i) {
      if (word[i] && !known[i]) {
        readable = false;
        break;
      }
    }
    if (readable) ++count;
  }
  return count;
}

int DFS(std::array<bool, 26>& known, int index, int learned) {
  if (learned == k) {
    return CountReadable(known);
  }

  int max_result = 0;
  for (int i = index; i < 26; ++i) {
    if (!known[i]) {
      known[i] = true;
      max_result = std::max(max_result, DFS(known, i + 1, learned + 1));
      known[i] = false;
    }
  }

  return max_result;
}

int main() {
  std::cin >> n >> k;

  if (k < 5) {
    std::cout << 0 << '\n';
    return 0;
  }

  std::string antic = "antic";
  std::array<bool, 26> known = {};
  for (char c : antic) {
    known[c - 'a'] = true;
  }

  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    
    std::array<bool, 26> word = {};
    for (char c : str) {
      word[c - 'a'] = true;
    }
    words_bit.push_back(word);
  }

  int result = DFS(known, 0, 5);
  std::cout << result << '\n';

  return 0;
}