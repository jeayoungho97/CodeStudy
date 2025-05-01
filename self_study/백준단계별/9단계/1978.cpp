#include <iostream>
#include <cmath>

bool is_prime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int N;
  std::cin >> N;

  int result = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    std::cin >> a;
    if (is_prime(a)) ++result;
  }

  std::cout << result << '\n';
  return 0;
}