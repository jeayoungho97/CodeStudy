#include <iostream>

int main() {
  int N, M;
  std::cin >> N >> M;

  int** A = new int*[N];
  int** B = new int*[N];

  for (int i = 0; i < N; ++i) {
    A[i] = new int[M];
    B[i] = new int[M];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> A[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> B[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cout << A[i][j] + B[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}