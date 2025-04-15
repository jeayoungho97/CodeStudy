#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;
  bool flag = true;
  if (str.length() < 2) {
    std::cout << "NO" << '\n';
    return 0;
  }

  for (size_t i = 0; i < str.length();) {
    if (str.substr(i, 2) == "pi") i += 2;
    else if (str.substr(i, 2) == "ka") i += 2;
    else if (str.substr(i, 3) == "chu") i += 3;
    else {
      flag = false;
      break;
    }
  }

  std::cout << (flag ? "YES" : "NO") << '\n';
  return 0;
}