#include <iostream>
#include <algorithm>

const int MAX = 987654321;
int main() {
  int n;
  std::cin >> n;
  
  int result = MAX;
  int cnt = n / 5;
  for (int i = 0; i <= cnt; ++i) {
    if ((n - 5 * i) % 3 == 0) {
      int sum = (n - 5 * i) / 3 + i; 
      result = std::min(result, sum);
    }
  }

  if (result == MAX) std::cout << -1 << '\n';
  else std::cout << result << '\n';

  return 0;
}