#include <iostream>

int main() {
  int ret = 0;
  for (int i = 0; i < 5; ++i) {
    int temp;
    std::cin >> temp;
    ret += temp * temp;
  }
  std::cout << ret % 10 << '\n';

  return 0;
}