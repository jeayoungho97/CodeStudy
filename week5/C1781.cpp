#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> homeworks;

  for (int i = 0; i < n; ++i) {
    int date, reward;
    std::cin >> date >> reward;
    homeworks.push_back({date, reward});
  }

  std::sort(homeworks.begin(), homeworks.end());

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  for (auto hw : homeworks) {
    int reward = hw.second;
    int date = hw.first;
    min_heap.push(reward);

    if ((int)min_heap.size() > date) {
      min_heap.pop();
    }
  }

  int result = 0;
  while (!min_heap.empty()) {
    result += min_heap.top();
    min_heap.pop();
  }

  std::cout << result << '\n';

  return 0;
}