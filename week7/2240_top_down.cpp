#include <iostream>
#include <algorithm>
#include <cstring>

int n, m, input[1004], dp[1004][2][34];

int go(int idx, int tree, int cnt) {
  if (cnt < 0) return -1e9;
  if (idx == n) return 0;
  int &ret = dp[idx][tree][cnt];
  if (ret != -1) return ret;

  return ret = std::max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == input[idx] - 1);
}

int main() {
  std::memset(dp, -1, sizeof(dp));
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> input[i];
  }

  std::cout << std::max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
  return 0;
}