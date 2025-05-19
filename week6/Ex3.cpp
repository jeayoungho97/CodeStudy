#include <iostream>

int main() {
  int n; std::cin >> n;

  int a[1001], cnt[1001], ret;

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    int max = 0;
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i] && max < cnt[j]) max = cnt[j];
    }
    cnt[i] = max + 1;
    ret = std::max(ret, cnt[i]);
  }
  std::cout << ret << '\n';

  return 0;
}