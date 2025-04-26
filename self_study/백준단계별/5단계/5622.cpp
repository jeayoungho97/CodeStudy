#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int result = 0;
  for (char ch : s) {
    int n = ch - 'A';
    int to_sum = 2;

    if (n >= 0) ++to_sum;
    if (n >= 3) ++to_sum;
    if (n >= 6) ++to_sum;
    if (n >= 9) ++to_sum;
    if (n >= 12) ++to_sum;
    if (n >= 15) ++to_sum;
    if (n >= 19) ++to_sum;
    if (n >= 22) ++to_sum;

    result += to_sum;
  }
  std::cout << result << '\n';
  return 0;
}

// A B C / D E F / G H I / J K  L  / M  N  O  / P  Q  R  S  / T  U  V  / W  X  Y  Z
// 0 1 2 / 3 4 5 / 6 7 8 / 9 10 11 / 12 13 14 / 15 16 17 18 / 19 20 21 / 22 23 24 25