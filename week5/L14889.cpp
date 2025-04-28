#include <iostream>
#include <vector>

const int MAX = 987654321;
int n, min_diff = MAX;
int map[21][21];

int main() {
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount (i) != n / 2) continue;

    std::vector<int> v1, v2;

    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        v1.push_back(j);
      }
      else {
        v2.push_back(j);
      }
    }

    int sum1 = 0, sum2 = 0;

    for (int a = 0; a < n / 2; ++a) {
      for (int b = 0; b < n / 2; ++b) {
        sum1 += map[v1[a]][v1[b]];
        sum2 += map[v2[a]][v2[b]];
      }

    }
    min_diff = std::min(min_diff, std::abs(sum1 - sum2));
  }

  std::cout << min_diff << '\n';

  return 0;
}