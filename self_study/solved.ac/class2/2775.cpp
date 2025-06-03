#include <iostream>
#include <cstring>

int dp[15][15];

int go(int k, int n) {
  if (k == 0) return n;
  if (n <= 0) return 0;

  int& ret = dp[k][n];
  if (ret != -1) return ret;

  ret = go(k - 1, n) + go(k, n - 1);
  return ret;
}

int main() {
  int t;
  std::cin >> t;
  std::memset(dp, -1, sizeof(dp));

  while (t--) {
    int k, n;
    std::cin >> k >> n;
    
    std::cout << go(k, n) << '\n';
  }
  return 0;
}