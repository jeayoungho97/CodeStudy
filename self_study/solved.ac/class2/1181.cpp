#include <iostream>
#include <set>
#include <string>

struct Cmp {
  bool operator()(const std::string& a, const std::string& b) const {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
  }
};

int main() {
  int n;
  std::cin >> n;
  std::set<std::string, Cmp> set;
  for (int i = 0; i < n; ++i) {
    std::string temp;
    std::cin >> temp;
    set.insert(temp);
  }

  for (std::string s : set) {
    std::cout << s << '\n';
  }
  return 0;
}