#include <iostream>
#include <cstring>

const int INF = 1e9;
int N, dp[1000001], track[1000001];

int go(int N) {
  if (N == 1) return 0;

  int &ret = dp[N];
  if (ret != -1) return ret;

  int cmp1 = (N % 2 == 0) ? 1 + go(N / 2) : INF;
  int cmp2 = (N % 3 == 0) ? 1 + go(N / 3) : INF;

  int next;
  if (cmp1 < cmp2) {
    ret = cmp1;
    next = N / 2;
  }
  else {
    ret = cmp2;
    next = N / 3;
  }

  int cmp3 = 1 + go(N - 1);
  if (cmp3 < ret) {
    ret = cmp3;
    next = N - 1;
  }

  track[N] = next;
  return ret;
}

int main() {
  std::cin >> N;
  std::memset(dp, -1, sizeof(dp));
  std::memset(track, -1, sizeof(track));


  std::cout << go(N) << '\n';

  for (int i = N; i >= 1;) {
    std::cout << i << ' ';
    i = track[i];
  }
  std::cout << '\n';

  return 0;
}