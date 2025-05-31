#include <iostream>
#include <vector>
#include <cstring>

int S, M, input[1004], dp[1004][2][34];

int go(int idx, int tree, int cnt) {
  if (cnt < 0) return -1e9;
  if (idx == S) return 0;
  int &ret = dp[idx][tree][cnt];

  if (ret != -1) return ret;

  return std::max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == input[idx] - 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> S >> M;
  for (int i = 0; i < S; ++i) {
    std::cin >> input[i];
  }

  std::memset(dp, -1, sizeof(dp));
  std::cout << std::max(go(0, 1, M - 1), go(0, 0, M)) << '\n';
  return 0;
}