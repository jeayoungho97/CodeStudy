#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> dp(k + 1, 0);
  for (int i = 0; i < n; ++i) {
    int w, v;
    std::cin >> w >> v;
    for (int j = k; j >= w; --j) {
      dp[j] = std::max(dp[j], dp[j - w] + v);
    }
  }
  std::cout << dp[k] << '\n';
  return 0;
}