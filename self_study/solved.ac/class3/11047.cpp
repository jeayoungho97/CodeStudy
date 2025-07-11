#include <iostream>

int main() {
  int n, k, result = 0;
  std::cin >> n >> k;

  int coin[10];

  for (int i = 0; i < n; ++i) {
    std::cin >> coin[i];
  }

  for (int i = n - 1; k > 0; --i) {
    if (coin[i] <= k) {
      result += k / coin[i];
      k %= coin[i];
    }
  }

  std::cout << result << '\n';
  return 0;
}