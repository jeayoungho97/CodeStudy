#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> data;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int result;

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int p, d;
    std::cin >> p >> d;
    data.push_back({d, p});
  }

  std::sort(data.begin(), data.end());

  for (int i = 0; i < n; ++i) {
    pq.push(data[i].second);

    if (pq.size() > data[i].first) {
      pq.pop();
    }
  }

  while (!pq.empty()) {
    result += pq.top();
    pq.pop();
  }
  std::cout << result << '\n';

  return 0;
}