#include <iostream>

int main() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  int x, y;
  x = (c * e - b * f) / (a * e - b * d);
  y = (c * d - a * f) / (b * d - a * e);
  std::cout << x << ' ' << y << '\n';
  return 0;
}