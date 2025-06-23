#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int n, k;

int dp[104][100004];
// dp[start][k] -> start 이후의 물건들에 대해 k 의 범위 안에서 나올 수 있는 최댓값

std::vector<std::pair<int, int>> items;

int go(int start, int k) {
  if (start == n) return 0;
  int& ret = dp[start][k];
  if (ret != -1) return ret;
  ret = go(start + 1, k); // 안 고르는 경우

  int w = items[start].first, v = items[start].second;
  if (k >= w) {
    ret = std::max(ret, v + go(start + 1, k - w)); // 고르는 경우
  }

  return ret;
}

int main() {
  std::cin >> n >> k;
  std::memset(dp, -1, sizeof(dp));

  for (int i = 0; i < n; ++i) {
    int w, v;
    std::cin >> w >> v;
    items.push_back({w, v});
  }

  std::cout << go(0, k) << '\n';
  return 0;
}