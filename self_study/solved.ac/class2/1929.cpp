#include <iostream>

const int MAX = 1'000'001;

int visited[MAX];

int main() {
  int m, n;
  std::cin >> m >> n;

  visited[1] = 1;
  for (int i = 2; i * i <= n; ++i) {
    if (visited[i]) continue;
    for (int j = i * i; j <= n; j += i) {
      visited[j] = 1;
    }
  }

  for (int i = m; i <= n; ++i) {
    if (!visited[i]) std::cout << i << '\n';
  }

  return 0;
}