#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N, B;
  std::cin >> N >> B;

  std::vector<char> result;

  while (N != 0) {
    int rem = N % B;

    if (rem >= 0 && rem <= 9) {
      result.push_back(rem + '0');
    }
    else result.push_back(rem - 10 + 'A');

    N /= B;
  }

  std::reverse(result.begin(), result.end());

  for (char ch : result) {
    std::cout << ch;
  }
  std::cout << '\n';
  return 0;
}