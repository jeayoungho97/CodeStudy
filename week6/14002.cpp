#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n; 
  std::cin >> n;

  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  std::vector<int> cnt(n, 1);
  std::vector<int> prev_list(n, -1);
  int val = 1, idx = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] < v[i] && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
        prev_list[i] = j;
        if (cnt[i] > val) {
          val = cnt[i];
          idx = i;
        }
      }
    }
  }

  std::cout << val << '\n';

  std::vector<int> result;
  while (idx != -1) {
    result.push_back(v[idx]);
    idx = prev_list[idx];
  }

  for (int i = result.size() - 1; i >= 0; --i) {
    std::cout << result[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}