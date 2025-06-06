#include <iostream>
#include <cstdio>
#include <vector>

int dp[10001];
int n, k, temp;

int main() {
  scanf("%d %d", &n, &k);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    if (temp >= 10001) continue;
    for (int j = temp; j <= k; ++j) {
      dp[j] += dp[j - temp];
    }
  }
  printf("%d\n", dp[k]);

  return 0;
}