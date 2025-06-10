#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::unordered_set<std::string> hear_set;
  std::vector<std::string> ret;

  for (int i = 0; i < n; ++i) {
    std::string name;
    std::cin >> name;
    hear_set.insert(name);
  }

  for (int i = 0; i < m; ++i) {
    std::string name;
    std::cin >> name;
    if (hear_set.find(name) != hear_set.end()) {
      ret.push_back(name);
    }
  }

  std::sort(ret.begin(), ret.end());

  std::cout << ret.size() << '\n';
  for (const auto& name : ret) {
    std::cout << name << '\n';
  }


  return 0;
}