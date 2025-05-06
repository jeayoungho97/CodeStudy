#include <iostream>
char map[51][51];

int main() {
  int N, M;
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> map[i][j];
    }
  }

  int result = 987654321;
  for (int i = 0; i < N - 7; ++i) {
    for (int j = 0; j < M - 7; ++j) {
      int count = 0;

      for (int y = i; y < i + 8; ++y) {
        for (int x = j; x < j + 8; ++x) {
          if (map[y][x] == 'W') ++count;
        } 
      }

      count = std::abs(count - 32);
      if (count < result) {
        result = count;
      }
    }
  }

  std::cout << result << '\n';
  return 0;
}