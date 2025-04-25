#include <iostream>
#include <vector>

int map[51][51];
int r, c, t;
int purifier_index;

constexpr int di[4] = {-1, 0, 1, 0};
constexpr int dj[4] = {0, 1, 0, -1};

std::vector<std::pair<int, int>> path1, path2;

constexpr int di_path1[4] = {0, -1, 0, 1};
constexpr int dj_path1[4] = {1, 0, -1, 0};

constexpr int di_path2[4] = {0, 1, 0, -1};
constexpr int dj_path2[4] = {1, 0, -1, 0};

void spread() {
  int next_add[51][51] = {{0}};

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] != 0 && map[i][j] != -1) {
        int num_spread = 0;

        for (int k = 0; k < 4; ++k) {
          int ni = i + di[k];
          int nj = j + dj[k];

          if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
          if (map[ni][nj] == -1) continue;

          next_add[ni][nj] += (map[i][j] / 5);
          ++num_spread;
        }

        map[i][j] -= num_spread * (map[i][j] / 5);
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      map[i][j] += next_add[i][j];
    }
  }
}

std::vector<std::pair<int, int>> make_path(int sy, const int dy[], const int dx[]) {
  std::vector<std::pair<int, int>> path;
  int count = 0;
  int y = sy;
  int x = 0;
  
  while(true) {
    int ny = y + dy[count];
    int nx = x + dx[count];

    if (ny == sy && nx == 0) break;
    if (ny < 0 || nx <0 || ny >= r || nx >= c) {
      ++count;
      ny = y + dy[count];
      nx = x + dx[count];
    }
    if (ny == sy && nx == 0) break;
    y = ny;
    x = nx;

    path.push_back({ny, nx});
  }
  return path;
}

void purify(std::vector<std::pair<int, int>> path) {
  for (int i = path.size() - 1; i > 0; --i) {
    map[path[i].first][path[i].second] = map[path[i - 1].first][path[i - 1].second];
  }
  map[path[0].first][path[0].second] = 0;
}

int main() {
  std::cin >> r >> c >> t;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == -1) {
        purifier_index = i;
      }
    }
  }

  path1 = make_path(purifier_index - 1, di_path1, dj_path1);
  path2 = make_path(purifier_index, di_path2, dj_path2);

  while (t--) {
    spread();
    purify(path1);
    purify(path2);
  }

  int result = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] != 0 && map[i][j] != -1) {
        result += map[i][j];
      }
    }
  }

  std::cout << result << '\n';
  return 0;
}