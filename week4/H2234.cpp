#include <iostream>

int n, m;
int max_room = 0, num_room = 0;
int max_room_after = 0;
int map[51][51];
bool visited[51][51];
constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0}; // 서-북-동-남

int count_room(int y, int x) {
  int result = 1;
  for (int i = 0; i < 4; ++i) {
    if (!(map[y][x] & (1 << i))) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (visited[ny][nx]) continue;
      visited[ny][nx] = true;
      result += count_room(ny, nx);
    }
  }
  return result;
}

void erase_wall(int y, int x) {
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if (map[y][x] & (1 << i)) {
      map[y][x] &= ~(1 << i);
      std::fill(&visited[0][0], &visited[0][0] + 51 * 51, false);
      visited[y][x] = true;
      max_room_after = std::max(max_room_after, count_room(y, x));
      map[y][x] |= (1 << i);
    }
  }
}

int main() {
  std::cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(!visited[i][j]) {
        visited[i][j] = true;
        max_room = std::max(count_room(i, j), max_room);
        ++num_room;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      erase_wall(i, j);
    }
  }

  std::cout << num_room << '\n';
  std::cout << max_room << '\n';
  std::cout << max_room_after << '\n';
  return 0;
}