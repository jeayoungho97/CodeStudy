#include <iostream>
#include <vector>


int main() {
  int M, N;
  std::cin >> M >> N;
  int sum = 0;
  int minimum;
  bool found_minimum = false;

  std::vector<bool> is_prime(N + 1, true);

  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (!is_prime[i]) continue;
    for (int j = i * i; j <= N; j += i) {
      is_prime[j] = false;
    }
  }

  for (int i = M; i <= N; ++i) {
    if (is_prime[i]) {
      if (!found_minimum) {
        minimum = i;
        found_minimum = true;
      }

      sum += i;
    }
  }

  if(!found_minimum) std::cout << -1 << '\n';
  else std::cout << sum << '\n' << minimum << '\n';

  return 0;
}