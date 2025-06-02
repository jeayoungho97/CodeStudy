#include <iostream>

int main() {
  int input[8];
  bool inc = false, dec = false;
  std::cin >> input[0];
  int prev = input[0];
  for (int i = 1; i < 8; ++i) {
    std::cin >> input[i];
    if (input[i] > prev) inc = true;
    else dec = true;

    prev = input[i];
  }

  if (inc && dec) std::cout << "mixed\n";
  else if (inc) std::cout << "ascending\n";
  else std::cout << "descending\n";

  return 0;
}