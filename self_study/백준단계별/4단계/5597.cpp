#include <iostream>

int main() {
  bool hw_done[30] = {};

  for (int i = 0; i < 28; ++i) {
    int student_number;
    std::cin >> student_number;

    hw_done[student_number - 1] = true;
  }

  for (int i = 0; i < 30; ++i) {
    if (!hw_done[i]) {
      std::cout << i + 1 << '\n';
    }
  }

  return 0;
}