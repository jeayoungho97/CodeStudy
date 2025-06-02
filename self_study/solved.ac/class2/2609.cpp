#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int minVal = std::min(a, b);

  int GCD, LCM;

  for (int i = 1; i <= minVal; ++i) {
    if (a % i == 0 && b % i == 0) GCD = i;
  }


  for (int div = a; div <= a * b; div += a) {
    if (div % b == 0) {
      LCM = div;
      break;
    }
  }

  std::cout << GCD << '\n' << LCM << '\n';

  return 0;
}