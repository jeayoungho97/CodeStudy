#include <iostream>

int main() {
  int T;
  std::cin >> T;

  const int coins[] = {25, 10, 5, 1};

  while (T--) {
    int C;
    std::cin >> C;
    
    for (int coin : coins) {
      std::cout << C / coin << ' ';
      C %= coin;
    }
    std::cout << '\n';
  }
  

  return 0;
}