#include <iostream>
#include <algorithm>

int main()
{
  int max_index = 0;
  int max_value = 0;
  int numbers[9];

  for (int i = 0; i < 9; ++i) {
    std::cin >> numbers[i];
    if (numbers[i] > max_value) {
      max_value = numbers[i];
      max_index = i + 1;
    }
  }

  std::cout << max_value << '\n';
  std::cout << max_index << '\n';
  
  return 0;
}