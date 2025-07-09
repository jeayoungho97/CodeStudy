#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
  int t;
  std::cin >> t;

  for (int test_case = 1; test_case <= t; test_case++) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr1(n), arr2(m);

    for (int i = 0; i < n; ++i) {
      std::cin >> arr1[i];
    }

    for (int i = 0; i < m; ++i) {
      std::cin >> arr2[i];
    }

    std::vector<int> &shorter = (n <= m) ? arr1 : arr2;
    std::vector<int> &longer = (n > m) ? arr1 : arr2;

    int result = INT_MIN;
    int limit = longer.size() - shorter.size();

    for (int i = 0; i <= limit; ++i) {
      int sum = 0;
      for (int j = 0; j < shorter.size(); ++j) {
        sum += shorter[j] * longer[i + j];
      }
      result = std::max(result, sum);
    }

    std::cout << "#" << test_case << " " << result << '\n';
  }

  return 0;
}