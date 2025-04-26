#include <iostream>
#include <string>

int finder(std::string s, std::string word) {
  int count = 0;
  auto start = 0;
  auto end = s.find(word);
  while (end != std::string::npos) {
    ++count;
    start = end + word.size();
    end = s.find(word, start);
  }
  return count;
}


int main() {
  std::string s;
  std::cin >> s;

  int result = s.size();

  std::string words[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
  for (std::string word : words) {
    result -= finder(s, word);
  }

  std::cout << result << '\n';

  return 0;
}