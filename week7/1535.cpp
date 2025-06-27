#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> L(n), J(n);
  for (int i = 0; i < n; ++i) std::cin >> L[i];
  for (int i = 0; i < n; ++i) std::cin >> J[i];

  std::vector<int> dp(101, 0);
  
  for (int i = 0; i < n; ++i) {
    for (int j = 100; j >= L[i] + 1; --j) {
      dp[j] = std::max(dp[j], dp[j - L[i]] + J[i]);
    }
  }

  int answer = 0;
  for (int i = 1; i <= 100; ++i) {
    answer = std::max(answer, dp[i]);
  }

  std::cout << answer << '\n';

  return 0;
}