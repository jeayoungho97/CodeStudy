#include <iostream>
#include <algorithm> // std::max_element, std::distance
#include <array>

int main()
{
  std::array<int, 9> numbers;
  for (int& number : numbers){
    std::cin >> number;
  }

  auto max_iter = std::max_element(numbers.begin(), numbers.end());
  int max_value = *max_iter;
  int max_index = std::distance(numbers.begin(), max_iter) + 1;

  std::cout << max_value << '\n';
  std::cout << max_index << '\n';

  return 0;
}