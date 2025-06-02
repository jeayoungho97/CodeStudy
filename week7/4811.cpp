#include <iostream>
#include <cstring>

using ll = long long;

ll dp[34][34];

ll go(int w, int h) {
  if (w == 0) return 1;
  if (h < 0) return 0;

  ll &ret = dp[w][h];
  if (ret != -1) return ret;

  ret = go(w - 1, h + 1) + go(w, h - 1);

  return ret;
}

int main() {
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) break;

    std::memset(dp, -1, sizeof(dp));

    std::cout << go(n, 0) << '\n';
  }

  return 0;
}