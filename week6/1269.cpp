#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int i = 0, j = 0;
  int result = 0;
  while (i < n && j < m) { 
    if (a[i] < b[j]) {
      ++result;
      ++i;
    }
    else if (a[i] > b[j]) {
      ++result;
      ++j;
    }
    else {
      ++i, ++j;
    }
  }

  result += n - i + m - j;

  std::cout << result << '\n';

  return 0;
}