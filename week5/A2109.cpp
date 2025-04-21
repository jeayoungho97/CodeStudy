#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> tasks;

  for (int i = 0; i < n; ++i) {
    int reward, date;
    std::cin >> reward >> date;
    tasks.push_back({date, reward});
  }

  std::sort(tasks.begin(), tasks.end());

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  for (auto task : tasks) {
    int reward = task.second;
    int date = task.first;
    pq.push(reward);

    if (static_cast<int>(pq.size()) > date) {
      pq.pop();
    }
  }

  int result = 0;

  while(!pq.empty()) {
    result += pq.top();
    pq.pop();
  }

  std::cout << result << '\n';

  return 0;
}