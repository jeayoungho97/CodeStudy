#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> baskets(n);
  for (int i = 0; i < n; ++i) {
    baskets[i] = i + 1;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    std::swap(baskets[a - 1], baskets[b - 1]);
  }

  for (int i = 0; i < n; ++i) {
    std::cout << baskets[i] << ' ';
  }
  std::cout << '\n';
  
  return 0;
}