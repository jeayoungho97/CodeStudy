#include <iostream>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, l;
  std::cin >> n >> l;

  std::pair<int, int> pool[n];

  for (int i = 0; i < n; ++i) {
    int left, right;
    std::cin >> left >> right;
    pool[i] = {left, right};
  }
  
  std::sort(pool, pool + n);
  int end = 0;
  int result = 0;
  
  for (int i = 0; i < n; ++i) {
    int left = pool[i].first;
    int right = pool[i].second;

    if (end <= left) {
      end = left;
    }

    if (end < right) {
      int len = right - end;
      int count = (len + l - 1) / l;
      end += count * l;
      result += count;
    }
  }
  std::cout << result << '\n';
  return 0;
}