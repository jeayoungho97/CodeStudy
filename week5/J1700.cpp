#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> usage(k);
  for (int i = 0; i < k; ++i) {
    std::cin >> usage[i];
  }

  std::vector<int> multitab;
  int result = 0;

  for (int i = 0; i < k; ++i) {
    if (std::find(multitab.begin(), multitab.end(), usage[i]) != multitab.end()) continue;
    
    int size = multitab.size();
    if (size < n) {
      multitab.push_back(usage[i]);
    }
    else {
      int index = 0;
      auto first = std::find(usage.begin() + i + 1, usage.end(), multitab[index]);

      for (int j = 1; j < size; ++j) {
        auto second = std::find(usage.begin() + i + 1, usage.end(), multitab[j]);
        if (first < second) {
          index = j;
          first = second;
        }
      }

      multitab[index] = usage[i];
      ++result;
    }
  }

  std::cout << result << '\n';
  return 0;
}