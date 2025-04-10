#include <iostream>
#include <algorithm>

const int MAX_N = 21;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int row, col, result;
char Map[MAX_N][MAX_N];

void go(int y, int x, int number, int count) {
  result = std::max(result, count);
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= row || nx < 0 || nx >= col) continue;
    int next = (1 << (int)(Map[ny][nx] - 'A'));
    if(((number & next) == 0)) go(ny, nx, number | next, count + 1);
  }
  return;
}

int main(){
  std::cin >> row >> col;

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      std::cin >> Map[i][j];
    }
  }

  go(0, 0, 1 << (int)(Map[0][0] - 'A'), 1);
  std::cout << result << '\n';
  return 0;
}