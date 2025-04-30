#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

const int MAX = 987654321;

int N, M, K;
int result = MAX;
int board[51][51];

// L D R U
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void rotate(int arr[51][51], int r, int c, int s) {
  for (int i = 1; i <= s; ++i) {
    int y = r - i;
    int x = c + i;
    int start_value = arr[y][x];
    int dir = 0;
    
    while (true) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if (ny == r - i && nx == c + i) {
        arr[y][x] = start_value;
        break;
      }

      if (std::abs(nx - c) > i || std::abs(ny - r) > i) {
        ++dir;

        ny = y + dy[dir];
        nx = x + dx[dir];
      }

      arr[y][x] = arr[ny][nx];
      y = ny;
      x = nx;
    }
  }
}

void min_cal(int arr[51][51]) {
  for (int i = 0; i < N; ++i) {
    int row_sum = 0;
    for (int j = 0; j < M; ++j) {
      row_sum += arr[i][j];
    }
    result = std::min(result, row_sum);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M >> K;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector<std::vector<int>> rotations;
  std::vector<int> index;
  for (int i = 0; i < K; ++i) {
    int r, c, s;
    std::cin >> r >> c >> s;
    std::vector<int> rotation = {r,c,s};
    rotations.push_back(rotation);
    index.push_back(i);
  }

  do {
    int temp_board[51][51];
    std::memcpy(temp_board, board, sizeof(board));

    for (int i = 0; i < index.size(); ++i) {
      rotate(temp_board, rotations[index[i]][0] - 1, rotations[index[i]][1] - 1, rotations[index[i]][2]);
    }

    min_cal(temp_board);
  }while (std::next_permutation(index.begin(), index.end()));

  std::cout << result << '\n';
  return 0;
}