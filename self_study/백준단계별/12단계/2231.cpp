#include <iostream>

int main() {
  int N;
  std::cin >> N;
  int result = 0;
  for (int i = N - 54; i < N; ++i) {
    int sum = i;
    int temp = i;
    while (temp != 0) {
      sum += temp % 10;
      temp /= 10;
    }

    if (sum == N) {
      result = i;
      break;
    }
  }

  std::cout << result << '\n';
  return 0;
}