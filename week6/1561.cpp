#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using ll = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll N;
  int M;
  std::cin >> N >> M;

  std::vector<int> rides(M);

  for (int i = 0; i < M; ++i) {
    std::cin >> rides[i];
  }
  int min_length = *min_element(rides.begin(), rides.end());
  ll left = 0, right = N * min_length;

  if (N <= M) {
    std::cout << N << '\n';
    return 0;
  }

  while (left < right) {
    ll mid = left + (right - left) / 2;

    ll cnt = M;
    for (int j = 0; j < M; ++j) {
      cnt += mid / rides[j];
      if(cnt >= N) break;
    }

    if (cnt < N) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }
  
  ll cnt = M;
  std::vector<int> idx;
  for (int j = 0; j < M; ++j) {
    cnt += right / rides[j];
    if (right % rides[j] == 0) idx.push_back(j + 1);
  }

  int ans = idx[idx.size() - 1 - (cnt - N)];
    
  std::cout << ans << '\n';
  return 0;
}