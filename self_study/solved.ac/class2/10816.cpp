// #include <iostream>
// #include <algorithm>
// #include <vector>

// int main() {
//   int n;
//   std::cin >> n;
//   std::vector<int> input(n);
//   for (int i = 0; i < n; ++i) {
//     std::cin >> input[i];
//   }
//   std::sort(input.begin(), input.end());

//   int m;
//   std::cin >> m;
//   std::vector<int> ret(m);
//   for (int i = 0; i < m; ++i) {
//     int temp;
//     std::cin >> temp;
//     auto low = std::lower_bound(input.begin(), input.end(), temp);
//     auto high = std::upper_bound(input.begin(), input.end(), temp);
//     ret[i] = high - low;
//   }

//   for (int i : ret) {
//     std::cout << i << ' ';
//   }
//   std::cout << '\n';

//   return 0;
// }

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  std::unordered_map<int, int> input;

  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp;
    std::cin >> temp;
    input[temp]++;
  }

  int m;
  std::cin >> m;
  std::vector<int> ret(m);
  for (int i = 0; i < m; ++i) {
    int temp;
    std::cin >> temp;
    ret[i] = input[temp];
  }

  for (int i : ret) {
    std::cout << i << ' ';
  }

  return 0;
}