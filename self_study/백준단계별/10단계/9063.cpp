#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N; std::cin >> N;
  int x_min = 10001, y_min = 10001;
  int x_max = -10001, y_max = -10001;
  for (int i = 0; i < N; ++i) {
    int x, y;
    std::cin >> x >> y;
    if (x < x_min) x_min = x;
    if (x > x_max) x_max = x;
    if (y < y_min) y_min = y;
    if (y > y_max) y_max = y;
  }

  std::cout << (x_max - x_min) * (y_max - y_min) << '\n'; 
  return 0;
}