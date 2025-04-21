#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> cow_time;

  for (int i = 0; i < n; ++i) {
    int arrival_time;
    int test_time;
    std::cin >> arrival_time >> test_time;
    cow_time.push_back({arrival_time, test_time});
  }
  std::sort(cow_time.begin(), cow_time.end());

  int result = 0;
  for (auto time : cow_time) {
    result = std::max(result, time.first);
    result += time.second;
  }

  std::cout << result << '\n';

  return 0;
}