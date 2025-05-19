#include <iostream>

int n, a[1001], ret = 1, cnt[1001], idx;
int prev_list[1001];
std::vector<int> v;

void go(int idx) {
  if (idx == -1) return;
  v.push_back(a[idx]);
  go(prev_list[idx]);
  return;
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::fill(prev_list, prev_list + 1001, -1);
  std::fill(cnt, cnt + 1001, 1);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
        prev_list[i] = j;
        if (ret < cnt[i]) {
          ret = cnt[i];
          idx = i;
        }
      }
    }
  }

  std::cout << ret << '\n';
  go(idx);

  for (int i = v.size() - 1; i >= 0; --i) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}