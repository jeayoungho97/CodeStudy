#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int result = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    std::cin >> a;

    bool flag = false;

    if (a == 1) flag = true;
    for (int j = 2; j <= a / 2; ++j) {
      if (a % j == 0) flag = true;
    }

    if (!flag) ++result;
  }

  std::cout << result << '\n';
  return 0;
}