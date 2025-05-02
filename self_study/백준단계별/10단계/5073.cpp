#include <iostream>
#include <algorithm>

int main() {
  while (true) {
    int length[3];
    std::cin >> length[0] >> length[1] >> length[2];

    if (length[0] == 0 && length[1] == 0 && length[2] == 0) break;

    std::sort(length, length + 3);

    if (length[2] >= length[0] + length[1]) std::cout << "Invalid\n";
    else {
      if (length[0] == length[1] && length[1] == length[2]) std::cout << "Equilateral\n";
      else if (length[0] == length[1] || length[1] == length[2] || length[2] == length[0]) std::cout << "Isosceles\n";
      else std::cout << "Scalene\n";
    }
  }

  return 0;
}