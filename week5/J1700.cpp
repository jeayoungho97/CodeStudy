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
    int current = usage[i];

    if (std::find(multitab.begin(), multitab.end(), current) != multitab.end()) continue;
    
    int size = multitab.size();
    if (size < n) {
      multitab.push_back(current);
      continue;
    }

    int index_to_remove = -1;
    int latest_use = -1;

    for (int j = 0; j < size; ++j) {
      int next_use = k + 1;

      for (int l = i + 1; l < k; ++l) {
        if (usage[l] == multitab[j]) {
          next_use = l;
          break;
        }
      }

      if (next_use > latest_use) {
        latest_use = next_use;
        index_to_remove = j;
      }

    }
    multitab[index_to_remove] = current;
    ++result;
  }

  std::cout << result << '\n';
  return 0;
}