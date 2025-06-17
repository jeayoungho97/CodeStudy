#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return p1.first < p2.first;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    points[i] = {x, y};
  }

  std::sort(points.begin(), points.end(), cmp);

  for (auto a : points) {
    std::cout << a.first << ' ' << a.second << '\n';
  }
  return 0;
}