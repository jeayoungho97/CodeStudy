#include <iostream>

int main() {
  int X;
  std::cin >> X;

  
  const int dy[2] = {-1, 1};
  const int dx[2] = {1, -1};
  int dir = 0;
  int y = 1, x = 1;
  
  for (int i = 1; i < X; ++i) {
    y += dy[dir];
    x += dx[dir];

    if (x == 0) {
      x = 1;
      dir = (dir + 1) % 2;
    }
    else if (y == 0) {
      y = 1;
      dir = (dir + 1) % 2;
    }
  }

  std::cout << y << '/' << x << '\n';
  return 0;
}