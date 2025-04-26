#include <iostream>
#include <algorithm>

int main() {
  int N, M = 0, sum = 0;
  double result;

  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    int temp;
    std::cin >> temp;
    M = std::max(M, temp);
    sum += temp;
  }

  result = (sum * 100.0) / (M * N);
  
  std::cout << result << '\n';
  return 0;
}