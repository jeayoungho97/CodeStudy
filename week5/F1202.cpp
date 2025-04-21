#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int num_jewels, num_bags;
  std::cin >> num_jewels >> num_bags;

  std::vector<std::pair<ll, ll>> jewels(num_jewels);

  for (int i = 0; i < num_jewels; ++i) {
    std::cin >> jewels[i].first >> jewels[i].second;
  }

  
  std::vector<ll> bags(num_bags);
  for (int i = 0; i < num_bags; ++i) {
    std::cin >> bags[i];
  }
  
  std::sort(jewels.begin(), jewels.end());
  std::sort(bags.begin(), bags.end());

  ll result = 0;
  int j = 0;
  std::priority_queue<ll> pq;

  for (int i = 0; i < num_bags; ++i) {
    while (j < num_jewels && jewels[j].first <= bags[i]) {
      pq.push(jewels[j].second);
      j++;
    }

    if (!pq.empty()) {
      result += pq.top();
      pq.pop();
    }
  }

  std::cout << result << '\n';
  return 0;
}