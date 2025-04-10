#include <iostream>
#include <algorithm>

constexpr int kMaxSize = 21;
constexpr int kDirectionCount = 4;

const int dy[kDirectionCount] = {-1, 0, 1, 0};
const int dx[kDirectionCount] = {0, 1, 0, -1};

int row, col;
int max_path_length = 0;
char board[kMaxSize][kMaxSize];

void DfsTraverse(int y, int x, int visited_bitmask, int count) {
  max_path_length = std::max(max_path_length, count);

  for (int i = 0; i < kDirectionCount; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= row || nx < 0 || nx >= col) continue;

    int next_bit = (1 << static_cast<int>(board[ny][nx] - 'A'));
    if(((visited_bitmask & next_bit) == 0)) {
      DfsTraverse(ny, nx, visited_bitmask | next_bit, count + 1);
    } 
  }
}

int main(){
  std::cin >> row >> col;

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      std::cin >> board[i][j];
    }
  }

  int start_bit = 1 << static_cast<int>(board[0][0] - 'A');
  DfsTraverse(0, 0, start_bit, 1);
  
  std::cout << max_path_length << '\n';
  return 0;
}