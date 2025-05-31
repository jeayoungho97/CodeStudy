#include <iostream>
#include <algorithm>
#include <cstring>

int n, m, dp[1004][2][34], input[1004];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> input[i];
  }

  // 초기 상태
  dp[0][0][0] = input[0] == 1 ? 1 : 0;
  if (m >= 1) {
    dp[0][1][1] = input[0] == 2 ? 1 : 0;
  }

  for (int t = 1; t < n; ++t) {
    for (int k = 0; k <= m; ++k) {
      for (int tree = 0; tree < 2; ++tree) {
        int &cur = dp[t][tree][k];

        // 나무를 바꾸지 않은 경우
        cur = dp[t - 1][tree][k];

        // 바꾸지 않은 경우와 바꾼 경우를 비교 (이전에 바꿨던 경우에만)
        if (k > 0) {
          cur = std::max(cur, dp[t - 1][tree ^ 1][k - 1]);
        }

        // 해당 상태에서 자두를 받는지 여부
        if (input[t] == tree + 1) ++cur;
      }
    }
  }

  // 마지막 모든 경우의 수끼리 비교
  int result = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= m; ++j) {
      result = std::max(result, dp[n - 1][i][j]);
    }
  }

  std::cout << result << '\n';
  return 0;
}