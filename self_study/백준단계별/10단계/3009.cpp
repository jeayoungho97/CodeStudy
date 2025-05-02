#include <iostream>
#include <map>

int main() {
  std::map<int, int> counter[2];
  for (int i = 0; i < 3; ++i) {
    int x, y;
    std::cin >> x >> y;
    ++counter[0][x];
    ++counter[1][y];
  }

  int x, y;
  for (auto a : counter[0]) {
    if (a.second == 1) x = a.first;
  }
  for (auto a : counter[1]) {
    if (a.second == 1) y = a.first;
  }

  std::cout << x << ' ' << y << '\n';
  return 0;
}