#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> list(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> list[i];
  }
  std::sort(list.begin(), list.end());

  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int temp;
    std::cin >> temp;

    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (list[mid] < temp) {
        left = mid + 1;
      }
      else if (list[mid] > temp) {
        right = mid - 1;
      }
      else {
        found = true;
        break;
      }
    }

    if (found) std::cout << 1 << '\n';
    else std::cout << 0 << '\n';
  }

return 0;
}