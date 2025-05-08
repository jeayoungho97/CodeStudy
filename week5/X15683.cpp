#include <iostream>
#include <vector>
#include <array>

const int INF = 70;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int N, M, result = INF;
std::array<std::array<int, 8>, 8> original_board;
std::vector<std::pair<int, int>> CCTV;

int count_zero(const std::array<std::array<int, 8>, 8>& board) {
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (board[i][j] == 0) ++sum;
    }
  }
  return sum;
}

void watch(int y, int x, int dir, std::array<std::array<int, 8>, 8>& board) {
  while (true) {
    y += dy[dir];
    x += dx[dir];
    if (y < 0 || x < 0 || y >= N || x >= M || board[y][x] == 6) break;
    if (board[y][x] == 0) board[y][x] = -1;
  }
}

void DFS(int idx, std::array<std::array<int, 8>, 8>& board) {
  if (idx == CCTV.size()) {
    result = std::min(result, count_zero(board));
    return;
  }

  auto pos = CCTV[idx];
  int y = pos.first;
  int x = pos.second;
  int num = board[y][x];

  switch(num) {
    case 1 : 
    for (int dir = 0; dir < 4; ++dir) {
      auto board_copy = board;
      watch(y, x, dir, board_copy);
      DFS(idx + 1, board_copy);
    }
    break;

    case 2 : 
    for (int dir = 0; dir < 2; ++dir) {
      auto board_copy = board;
      watch(y, x, dir, board_copy);
      watch(y, x, dir + 2, board_copy);
      DFS(idx + 1, board_copy);
    }
    break;

    case 3 : 
    for (int dir = 0; dir < 4; ++dir) {
      auto board_copy = board;
      watch(y, x, dir, board_copy);
      watch(y, x, (dir + 1) % 4 , board_copy);
      DFS(idx + 1, board_copy);
    }
    break;

    case 4 : 
    for (int dir = 0; dir < 4; ++dir) {
      auto board_copy = board;
      watch(y, x, dir, board_copy);
      watch(y, x, (dir + 1) % 4, board_copy);
      watch(y, x, (dir + 2) % 4, board_copy);
      DFS(idx + 1, board_copy);
    }
    break;

    case 5 : 
    auto board_copy = board;
    for (int dir = 0; dir < 4; ++dir) {
      watch(y, x, dir, board_copy);
    }
    DFS(idx + 1, board_copy);
    break;
  }
}


int main() {
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> original_board[i][j];
      if (original_board[i][j] != 0 && original_board[i][j] != 6) {
        CCTV.push_back({i, j});
      }
    }
  }

  DFS(0, original_board);

  std::cout << result << '\n';
  return 0;
}