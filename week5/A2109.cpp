#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main() {
  int num_tasks;
  std::cin >> num_tasks;

  std::vector<std::pair<int, int>> tasks;  // {deadline, reward}

  for (int i = 0; i < num_tasks; ++i) {
    int reward, deadline;
    std::cin >> reward >> deadline;
    tasks.emplace_back(deadline, reward);
  }

  // Sort tasks by deadline (earliest first)
  std::sort(tasks.begin(), tasks.end());

  // Min-heap to keep top rewards under each deadline constraint
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  for (const auto& task : tasks) {
    int deadline = task.first;
    int reward = task.second;

    min_heap.push(reward);

    // If we exceed the number of available days, discard the least rewarding task
    if (static_cast<int>(min_heap.size()) > deadline) {
      min_heap.pop();
    }
  }

  int total_reward = 0;
  while (!min_heap.empty()) {
    total_reward += min_heap.top();
    min_heap.pop();
  }

  std::cout << total_reward << '\n';
  return 0;
}
