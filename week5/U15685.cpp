#include <iostream>
#include <vector>
#include <algorithm>

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

std::vector<std::vector<int>> directions[4];
bool map[101][101] = {};

void make_directions(int dir) {
  directions[dir].resize(11);

  directions[dir][0] = {dir};

  for (int g = 1; g <= 10; ++g) {
    std::vector<int> prev = directions[dir][g - 1];
    std::vector<int> rev = prev;
    std::reverse(rev.begin(), rev.end());
    for (int &d : rev) d = (d + 1) % 4;
    prev.insert(prev.end(), rev.begin(), rev.end());
    directions[dir][g] = prev;
  }
}

void go (int x, int y, std::vector<int> path) {
  map[y][x] = true;

  for (int dir : path) {
    x += dx[dir];
    y += dy[dir];
    if (x < 0 || y < 0 || x > 100 || y > 100) continue;
    map[y][x] = true;
  }
  return;
}

int main() {
  int N;
  std::cin >> N;
  
  for (int dir = 0; dir < 4; ++dir) {
    make_directions(dir);
  }

  for (int i = 0; i < N; ++i) {
    int x, y, dir, gen;
    std::cin >> x >> y >> dir >> gen;

    go(x, y, directions[dir][gen]);
  }

  int result = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) ++result;
    }
  }

  std::cout << result << '\n';
  return 0;
}