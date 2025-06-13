#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> data;

  for (int i = 0; i < n; ++i) {
    int weight, height;
    std::cin >> weight >> height;
    data.push_back({weight, height});
  }

  std::vector<int> ret;
  for (auto person : data) {
    int rank = 1;
    for (auto other : data) { 
      if (other.first > person.first && other.second > person.second) {
        ++rank;
      }
    }
    ret.push_back(rank);
  }

  for (int i : ret) {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}

/* 
80 180 = 70 190 = 75 178 ? NO!

80 180 > 75 178

결국 각자의 등수가 중요함 -> 나보다 덩치 큰 사람이 몇명 있는지만 확인하면 됨.
*/

