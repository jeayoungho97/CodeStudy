#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  std::cin >> N;
  
  long long result = -100'000'000;
  long long sum = 0;

  for (int i = 0; i < N; ++i) {
    long long input;
    std::cin >> input;

    sum = std::max(input, sum + input);
    result = std::max(result, sum);
  }

  std::cout << result << '\n';
  return 0;
}