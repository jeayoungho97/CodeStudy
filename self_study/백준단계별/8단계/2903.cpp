#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int length = (1 << N) + 1;
  std::cout << length * length << '\n';

  return 0;
}