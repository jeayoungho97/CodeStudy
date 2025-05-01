#include <iostream>
#include <vector>

int main() {
  int N, K;
  std::cin >> N >> K;
  std::vector<int> factors;

  for (int i = 1; i <= N / 2; ++i) {
    if (N % i == 0) factors.push_back(i);
  }
  factors.push_back(N);

  if (K > factors.size()) {
    std::cout << 0 << '\n';
  }
  else {
    std::cout << factors[K - 1] << '\n';
  }

  return 0;
}