#include <iostream>

int main() {
  int N, K;
  std::cin >> N >> K;
  int ret = 1;
  for (int i = 1; i <= N; ++i) {
    ret *= i;
  }
  for (int i = 1; i <= K; ++i) {
    ret /= i;
  }
  for (int i = 1; i <= (N - K); ++i) {
    ret /= i;
  }
  std::cout << ret << '\n';
  return 0;
}