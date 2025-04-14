#include <iostream>
#include <cstring>

int n, m;
int max_result = 0;
char map[4][4];
int bit_mask[4];
bool visited[4][4];

int go(int y, int x, int count) {
  visited[y][x] = true;
  int number = map[y][x] - '0';
  if (bit_mask[y] & (1 << x)) { // 세로
    if (y + 1 == n || !(bit_mask[y + 1] & (1 << x))) {
      return 10 * count + number;
    }
    return go(y + 1, x, 10 * count + number);
  }

  else { //가로
    if (x + 1 == m || (bit_mask[y] & (1 << (x + 1)))) {
      return 10 * count + number;
    }
    return go(y, x + 1, 10 * count + number);
  }

}

int main() {
  std::cin >> n >> m;

  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i < (1 << (n * m)); ++i) {
    for (int j = 0; j < n; ++j) {
      bit_mask[j] = 0;
      for (int k = 0; k < m; ++k) {
        bit_mask[j] |= (i & (1 << (m * j + k))) ? (1 << k) : 0;
      }
    }

    int result = 0;
    std::memset(visited, 0, sizeof(visited));
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if(!visited[j][k]) result += go(j, k, 0);
      }
    }

    max_result = std::max(max_result, result);
  }

  std::cout << max_result << '\n';
  return 0;

}