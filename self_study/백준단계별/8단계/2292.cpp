#include <iostream>

int main() {
  long long N;
  std::cin >> N;

  long long range = 1;
  int count = 1;
  while (N > range) {
    range += 6 * count;
    ++count;
  }

  std::cout << count << '\n';
  return 0;
}