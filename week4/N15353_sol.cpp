#include <iostream>
#include <string>
#include <algorithm>

std::string string_add(std::string a, std::string b) {
  int sum = 0;
  std::string ret = "";

  while (a.size() || b.size() || sum) {
    if (a.size()) {
      sum += a.back() - '0';
      a.pop_back();
    }

    if (b.size()) {
      sum += b.back() - '0';
      b.pop_back();
    }

    ret += (sum % 10) + '0';
    sum /= 10;
  }
  std::reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  std::string a, b;
  std::cin >> a >> b;

  std::cout << string_add(a, b) << '\n';
  return 0;
}