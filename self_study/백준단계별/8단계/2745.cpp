#include <iostream>
#include <string>

int main() {
  std::string N;
  int B;
  std::cin >> N >> B;

  int result = 0;
  int multiplier = 1;

  for (int i = N.size() - 1; i >= 0; --i) {
    int value;
    if (N[i] >= '0' && N[i] <= '9') value = N[i] - '0';
    else value = N[i] - 'A' + 10;

    result += value * multiplier;
    multiplier *= B;
  }

  std::cout << result << '\n';
  return 0;
}