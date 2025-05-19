#include <iostream>
#include <algorithm>

const int MAX = 987654321;
int n, m, result = MAX;
int arr[300000];

bool search(int estimate_val) {
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    ret += arr[i] / estimate_val;
    
    if (arr[i] % estimate_val) ++ret;
  }

  return ret <= n;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n >> m;

  int left = 1, right = 0, mid;

  for (int i = 0; i < m; ++i) {
    std::cin >> arr[i];
    right = std::max(right, arr[i]);
  }

  while (left <= right) {
    mid = left + (right - left) / 2;

    if (search(mid)) {
      result = std::min(result, mid);
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }

  std::cout << result << '\n';

  return 0;
}