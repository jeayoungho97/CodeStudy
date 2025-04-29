#include <iostream>
#include <vector>
#include <queue>

const int MAX = 101;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N;
int board[MAX][MAX];
std::vector<std::pair<int, char>> operation;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  int K;
  std::cin >> K;

  for (int i = 0; i < K; ++i) {
    int y, x;
    std::cin >> y >> x;
    board[y - 1][x - 1] = 1;
  }

  int L;
  std::cin >> L;

  for (int i = 0; i < L; ++i) {
    int X;
    char C;
    std::cin >> X >> C;
    operation.push_back({X, C});
  }

  int time = 0, operation_index = 0;
  int x_pos = 0, y_pos = 0;
  board[x_pos][y_pos] = 2;

  std::queue<std::pair<int, int>> snake;
  snake.push({x_pos, y_pos});
  int dir = 0;

  while (true) {
    if (operation_index < operation.size() && operation[operation_index].first == time) {
      dir = (dir + (operation[operation_index].second == 'L' ? 3 : 1)) % 4;
      ++operation_index;
    }
    
    y_pos += dy[dir];
    x_pos += dx[dir];
    ++time;

    // 벽에 부딪히거나 자기 몸에 닿으면 break
    if (y_pos < 0 || y_pos >= N || x_pos < 0 || x_pos >= N || board[y_pos][x_pos] == 2) break;

    // 사과가 없다면 꼬리 제거
    if (board[y_pos][x_pos] != 1) {
      board[snake.front().first][snake.front().second] = 0;  
      snake.pop();
    }

    snake.push({y_pos, x_pos});
    board[y_pos][x_pos] = 2;
  }

  std::cout << time << '\n';
  return 0;
}

  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j < N; ++j) {
  //     std::cout << board[i][j] << ' ';
  //   }
  //   std::cout << '\n';
  // }

  // std::cout << "-------------\n\n";

  // for (auto a : operation) {
  //   std::cout << a.first << ' ' << a.second << '\n';
  // }