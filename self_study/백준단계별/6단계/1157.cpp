#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int visited[26] = {0};

  for (char ch : s) {
    ch = std::toupper(ch);
    ++visited[ch - 'A'];
  }

  int index = -1, count = 0, M = 0;
  for (int i = 0; i < 26; ++i) {
    if (visited[i] == M) {
      ++count;
    }
    else if (visited[i] > M) {
      count = 1;
      M = visited[i];
      index = i;
    }
  }

  if (count > 1) {
    std::cout << '?' << '\n';
  }
  else {
    std::cout << static_cast<char>(index + 'A') << '\n';
  }
  
  return 0;
}