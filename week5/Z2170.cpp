#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> list(N);

  for (int i = 0; i < N; ++i) {
    std::cin >> list[i].first >> list[i].second;
  }
  std::sort(list.begin(), list.end());

  auto [start, end] = list[0];

  int result = 0;

  for (int i = 1; i < N; ++i) {
    int x = list[i].first;
    int y = list[i].second;
    if (x > end) {
      result += (end - start);
      start = x;
      end = y;
    }
    else {
      end = std::max(end, y);
    }
  }
  result += (end - start);

  std::cout << result << '\n';
  return 0;
}