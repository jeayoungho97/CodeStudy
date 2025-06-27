#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 10000;

int main() {
  int n, m;
  std::cin >> n >> m;
  
  std::vector<int> M(n), C(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> M[i];
  }

  int max_cost = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> C[i];
    max_cost += C[i];
  }

  std::vector<int> dp(max_cost + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = max_cost; j >= C[i]; --j) {
      dp[j] = std::max(dp[j], dp[j - C[i]] + M[i]);
    }
  }

  int answer = MAX;
  for (int i = 0; i <= max_cost; ++i) {
    if (dp[i] >= m) {
      answer = std::min(answer, i);
    }
  }

  std::cout << answer << '\n';
  return 0;
}