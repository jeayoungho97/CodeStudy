#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

double result = 1.0, ans = 0.0;

int main() {
  int N;
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    double temp;
    std::cin >> temp;

    result *= temp;
    result = std::max(result, temp);
    ans = std::max(ans, result);
  }

  std::cout << std::fixed << std::setprecision(3) << ans << '\n';
  // std::cout << std::round(ans * 10000.0) / 10000.0 << '\n';  <-- wrong!
  return 0;
}