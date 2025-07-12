#include <iostream>
#include <string>

std::string str1, str2;
std::pair<int, std::string> dp[41][41];

std::pair<int, std::string> go(int i, int j) {
  std::pair<int, std::string> result = {0, ""};

  for (int k = i; k < str1.size(); ++k) {
    for (int l = j; l < str2.size(); ++l) {
      if (str1[k] == str2[l]) {
        std::pair<int,std::string> &temp = dp[k][l];
        if (temp.first > result.first) {
          result = temp;
        }
        else {
          auto next = go(k + 1, l + 1);
          temp.first = next.first + 1;
          temp.second = str1[k] + next.second;
          if (temp.first > result.first) {
            result = temp;
          }
        }
      }
    }
  }

  return result;
}

int main() {
  std::cin >> str1 >> str2;

  std::cout << go(0, 0).second << '\n';
  return 0;
}