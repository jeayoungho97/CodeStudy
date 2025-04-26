#include <iostream>
#include <string>

int main() {
  int N;
  std::cin >> N;

  std::string* s = new std::string[N];

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2 * i + 1; ++j) {
      s[i] += '*';
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - i - 1; ++j) {
      std::cout << ' ';
    }
    std::cout << s[i] << '\n';
  }

  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j < N - i - 1; ++j) {
      std::cout << ' ';
    }
    std::cout << s[i] << '\n';
  }
  return 0;
}