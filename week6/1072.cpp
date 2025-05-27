#include <iostream>

using ll = long long;

int main() {
  ll X, Y;
  std::cin >> X >> Y;
  ll pt = Y * 100 / X;
  if (pt >= 99) {
    std::cout << -1 << '\n';
    return 0;
  }

  ll left = 1, right = 1e9;
  ll ans = -1;

  while (left <= right) {
    ll mid = left + (right - left) / 2;
    ll cmp = (Y + mid) * 100 / (X + mid);

    if (cmp > pt) {
      ans = mid;
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }

  std::cout << ans << '\n';
  return 0;
}