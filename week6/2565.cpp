#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, result = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> wire(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    wire[i] = {a, b};
  }

  std::sort(wire.begin(), wire.end());

  std::vector<int> cnt(n, 1);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (wire[j].second < wire[i].second && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
        result = std::max(result, cnt[i]);
      }
    }
  }

  std::cout << n - result << '\n';
  return 0;
}