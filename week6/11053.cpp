#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> v(n), cnt(n);
  std::fill(cnt.begin(), cnt.end(), 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] < v[i] && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
      }
    }
  }

  std::cout << *(std::max_element(cnt.begin(), cnt.end())) << '\n';

  return 0;
}