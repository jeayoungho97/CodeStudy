#include <iostream>
#include <vector>
#include <algorithm>

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int N, M, T;
std::vector<std::vector<int>> map(50);

void compare() {
  int to_erase[50][50] = {};

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (map[y][x] == 0) continue;

      for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= N) continue;
        if (nx < 0) nx += M;
        if (nx >= M) nx -= M;

        if (map[ny][nx] == map[y][x]) {
          to_erase[y][x] = true;
        }
      }
    }
  }

  bool flag = false;
  int sum = 0, count = 0;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if(to_erase[y][x]) {
        map[y][x] = 0;
        flag = true;
      } else if (map[y][x] != 0) {
        sum += map[y][x];
        ++count;
      }
    } 
  }

  if (!flag) {
    const double avg = static_cast<double>(sum) / count;
    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < M; ++x) {
        if (map[y][x] == 0) continue;

        if (map[y][x] > avg) {
          --map[y][x];
        }
        else if (map[y][x] < avg) {
          ++map[y][x];
        }
      } 
    }

  }

}

int main() {
  std::cin >> N >> M >> T;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int input;
      std::cin >> input;
      map[i].push_back(input);
    }
  }

  for (int i = 0; i < T; ++i) {
    int x, d, k;
    std::cin >> x >> d >> k;

    for (int j = x; j <= N; j += x) {
      std::rotate(map[j - 1].begin(), d ? map[j - 1].begin() + k : map[j - 1].begin() + M - k,map[j - 1].end());
    }
    compare();
  }

  int result = 0;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      result += map[y][x];
    }
  }

  std::cout << result << '\n';
  return 0;
}

// else if 를 무시하지 말자..