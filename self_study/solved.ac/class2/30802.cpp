#include <iostream>

int main() {
  int n, t, p;
  std::cin >> n;
  int arr[6];
  for (int i = 0; i < 6; ++i) {
    std::cin >> arr[i];
  }
  std::cin >> t >> p;

  int ret = 0;
  for (int i : arr) {
    ret += i / t;
    if (i % t) ++ret;
  }
  std::cout << ret << '\n';
  std::cout << n / p << ' ' << n % p << '\n';

  return 0;
}