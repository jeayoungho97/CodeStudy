#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int num_elements;
  std::cin >> num_elements;

  std::vector<int> lis;

  for (int i = 0; i < num_elements; ++i) {
    int number;
    std::cin >> number;

    auto it = std::lower_bound(lis.begin(), lis.end(), number);

    if (it == lis.end()) {
      lis.push_back(number);
    }
    else {
      *it = number;
    }

    for (const auto& val : lis) std::cout << val << ' ';
    std::cout << '\n';
  }

  std::cout << lis.size() << '\n';
  return 0;
}