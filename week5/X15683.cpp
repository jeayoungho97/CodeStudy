#include <iostream>
#include <vector>
#include <array>

const int INF = 70;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int N, M, result = INF;
std::array<std::array<int, 8>, 8> original_board;
std::vector<std::pair<int, int>> CCTV;
const std::vector<std::vector<std::vector<int>>> cctv_dirs = {
  {},
  {{0}, {1}, {2}, {3}},
  {{0, 2}, {1, 3}},
  {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
  {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
  {{0, 1, 2, 3}}
};

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

  auto [y, x] = CCTV[idx];
  int type = board[y][x];

  for (const auto& dirs : cctv_dirs[type]) {
    auto board_copy = board;
    for (int dir : dirs) {
      watch(y, x, dir, board_copy);
    }
    DFS(idx + 1, board_copy);
  }
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

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