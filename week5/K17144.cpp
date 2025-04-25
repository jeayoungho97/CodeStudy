#include <iostream>

int map[51][51];
int r, c, t;
int purifier_index;
constexpr int di[4] = {-1, 0, 1, 0};
constexpr int dj[4] = {0, 1, 0, -1};

void spread_and_purify() {
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

  //공기청정기 상단부
  for (int i = purifier_index - 2; i > 0; --i) {
    map[i][0] = map[i - 1][0];
  }
  for (int i = 0; i < c - 1; ++i) {
    map[0][i] = map[0][i + 1];
  }
  for (int i = 0; i < purifier_index - 1; ++i) {
    map[i][c - 1] = map[i + 1][c - 1];
  }
  for (int i = c - 2; i > 0; --i) {
    map[purifier_index - 1][i + 1] = map[purifier_index - 1][i];
  }
  map[purifier_index - 1][1] = 0;

  //공기청정기 하단부
  for (int i = purifier_index + 1; i < r - 1; ++i) {
    map[i][0] = map[i + 1][0];
  }
  for (int i = 0; i < c - 1; ++i) {
    map[r - 1][i] = map[r - 1][i + 1];
  }
  for (int i = r - 1; i > purifier_index; --i) {
    map[i][c - 1] = map[i - 1][c - 1];
  }
  for (int i = c - 2; i > 0; --i) {
    map[purifier_index][i + 1] = map[purifier_index][i];
  }
  map[purifier_index][1] = 0;
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

  while (t--) {
    spread_and_purify();
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