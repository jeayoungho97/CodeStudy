#include <iostream>
#include <string>

int main() {
  int ret, idx;
  for (int i = 0; i < 3; ++i) {
    std::string temp;
    std::cin >> temp;

    bool test = true;
    for (char ch : temp) {
      if (!std::isdigit(ch)) test = false;
    }

    if (test) {
      ret = std::stoi(temp);
      idx = i;
    }
  }
  
  ret += (3 - idx);

  std::string ans;
  if (ret % 3 == 0) ans += "Fizz";
  if (ret % 5 == 0) ans += "Buzz";

  if (ret % 3 != 0 && ret % 5 != 0) {
    std::cout << ret << '\n';
  }
  else {
    std::cout << ans << '\n';
  }

  return 0;
}