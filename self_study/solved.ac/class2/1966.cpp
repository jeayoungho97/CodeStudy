#include <iostream>
#include <queue>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, m;
    std::cin >> n >> m;

    std::queue<std::pair<int, bool>> q;
    std::priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
      int order;
      std::cin >> order;
      bool is_target = (i == m);

      q.push({order, is_target});
      pq.push(order);
    }

    int cnt = 0;
    while (true) {
      int curr_priority = q.front().first;
      bool is_target = q.front().second;
      q.pop();

      if (curr_priority < pq.top()) {
        q.push({curr_priority, is_target});
      }
      else {
        ++cnt;
        pq.pop();

        if (is_target) {
          std::cout << cnt << '\n';
          break;
        }
      }
    }
  }
  return 0;
}