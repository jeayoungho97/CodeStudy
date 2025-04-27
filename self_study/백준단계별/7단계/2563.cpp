#include <iostream>

int main() {
  bool visited[100][100] = {};
  int N;
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    int a, b;
    std::cin >> a >> b;
    for (int y = a; y < a + 10; ++y) {
      for (int x = b; x < b + 10; ++x) {
        visited[y][x] = true;
      }
    }
  }

  int result = 0;
  for (int y = 0; y < 100; ++y) {
    for (int x = 0; x < 100; ++x) {
      if (visited[y][x]) ++result;
    }
  }

  std::cout << result << '\n';
  return 0;
}