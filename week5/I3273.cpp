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

  int goal;
  std::cin >> goal;

  std::sort(v.begin(), v.end());

  int left = 0, right = n - 1, result = 0;

  while (left < right) {
    int sum = v[left] + v[right];

    if (sum < goal) ++left;
    else if (sum > goal) --right;
    else {
      ++result;
      ++left;
      --right;
    }
  }

  std::cout << result << '\n';
  return 0;
}