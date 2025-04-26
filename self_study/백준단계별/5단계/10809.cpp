#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  int alphabet[26];
  for (int& i : alphabet) {
    i = -1;
  }

  int size = s.size();
  for (int i = 0; i < size; ++i) {
    if (alphabet[s[i] - 'a'] == -1) {
      alphabet[s[i] - 'a'] = i;
    }
  }

  for (int i : alphabet) std::cout << i << ' ';
  std::cout << '\n';

  return 0;
}