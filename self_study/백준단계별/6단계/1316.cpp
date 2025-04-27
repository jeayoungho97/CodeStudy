#include <iostream>
#include <string>

int main() {
  int N;
  std::cin >> N;

  int result = 0;

  while (N--) {
    std::string str;
    std::cin >> str;
    
    bool visited[26] = {};
    char prev = str[0];
    bool flag = true;

    for (char ch : str) {
      if (visited[ch - 'a']) {
        flag = false;
        break;
      }

      if (ch != prev) {
        visited[prev - 'a'] = true;
        prev = ch;
      }
    } 

    if (flag) ++result;

  }

  std::cout << result << '\n';
  return 0;
}