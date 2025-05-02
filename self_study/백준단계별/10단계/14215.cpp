#include <iostream>
#include <algorithm>

int main() {
  int length[3];
  std::cin >> length[0] >> length[1] >> length[2];
  std::sort(length, length + 3);
  
  if (length[2] >= length[0] + length[1]) std::cout << 2 * (length[0] + length[1]) - 1 << '\n';
  else std::cout << length[0] + length[1] + length[2] << '\n';

  return 0;
}