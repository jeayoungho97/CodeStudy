#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int start = 2;

  while (N != 1) {
    int div;
    for (div = start; div * div <= N; ++div) {
      if (N % div == 0) {
        std::cout << div << '\n';
        N /= div;
        break;
      }
    }
    
    if (div * div > N) {
      std::cout << N << '\n';
      break;
    }

    start = div;
  }

  return 0;
}