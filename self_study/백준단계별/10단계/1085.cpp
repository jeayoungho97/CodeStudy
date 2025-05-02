#include <iostream>
#include <algorithm>

int main() {
  int x, y, w, h;
  std::cin >> x >> y >> w >> h;
  int x_min = std::min(x, w - x);
  int y_min = std::min(y, h - y);
  int result = std::min(x_min, y_min);
  std::cout << result << '\n';
  return 0;
}