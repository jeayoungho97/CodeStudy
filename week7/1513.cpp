#include <iostream>
#include <vector>
#include <cstring>

const int divider = 1000007;
int n, m, c;
int map[51][51], dp[51][51][51][51];

int go(int count, int y, int x, int last_visited) {
  if (y >= n || y < 0 || x >= m || x < 0) return 0;
  if (map[y][x] != 0 && map[y][x] < last_visited) return 0;

  if (y == n - 1 && x == m - 1) {
    if (count == 0 && map[y][x] == 0) return 1;
    if (count == 1 && map[y][x] != 0) return 1;
    return 0;
  }

  int& ret = dp[count][y][x][last_visited];
  if (ret != -1) return ret;
  ret = 0;

  if (map[y][x] != 0 && map[y][x] > last_visited) {
    last_visited = map[y][x];
    if (count != 0) {
      ret = go(count - 1, y + 1, x, last_visited) + go(count - 1, y, x + 1, last_visited);
    }
  }
  else {
    ret = go(count, y + 1, x, last_visited) + go(count, y, x + 1, last_visited);
  }

  ret %= divider;

  // std::cout << "dp[" << count << "][" << y << "][" << x << "] = " << ret << '\n';
  return ret;
}

int main() {

  std::cin >> n >> m >> c;

  for (int i = 1; i <= c; ++i) {
    int y, x;
    std::cin >> y >> x;
    map[y - 1][x - 1] = i;
  }
  
  std::memset(dp, -1, sizeof(dp));

  for (int i = 0; i <= c; ++i) {
    std::cout << go(i, 0, 0, 0) << ' ';
  }
  std::cout << '\n';

  return 0;
}