#include <iostream>
#include <stack>
#include <utility>

int main() {
  int number_of_people;
  std::cin >> number_of_people;

  std::stack<std::pair<int,int>> height_stack;
  int64_t visible_pairs = 0;

  for (int i = 0; i < number_of_people; ++i) {
    int current_height;
    std::cin >> current_height;
    int count = 1;

    // pop stack elements <= current_height
    while (!height_stack.empty() && height_stack.top().first <= current_height) {
      visible_pairs += height_stack.top().second;

      // if stack_top == current_heigth, accumulate their count
      if (height_stack.top().first == current_height) {
        count += height_stack.top().second;
      }

      height_stack.pop();
    }

    // if stack is not empty, it means that there's tall one still there
    if (!height_stack.empty()) {
      ++visible_pairs;
    }

    height_stack.push({current_height, count});
  }

  std::cout << visible_pairs << '\n';
  return 0;
}