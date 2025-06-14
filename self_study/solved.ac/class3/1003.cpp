#include <iostream>

std::pair<int, int> dp[41];

int main() {
  int t;
  std::cin >> t;

  dp[0] = {1, 0};
  dp[1] = {0, 1};
  for (int i = 2; i < 41; ++i) {
    dp[i].first = dp[i - 1].first + dp[i - 2].first;
    dp[i].second = dp[i - 1].second + dp[i - 2].second;
  }

  while (t--) {
    int n;
    std::cin >> n;
    std::cout << dp[n].first << ' ' << dp[n].second << '\n';
  }
  return 0;
}