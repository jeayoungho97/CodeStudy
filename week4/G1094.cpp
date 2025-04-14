#include <iostream>

int main() {
  bool arr[7] = {};
  int x;
  int result = 0;

  std::cin >> x;
  for (int i = 0; i < 7; ++i) {
    if (x & (1 << i)) {
      arr[i] = true;
      ++result;
    }
  }
  std::cout << result << '\n';
  return 0;
}