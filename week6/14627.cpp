#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

bool check(int val, int num, const std::vector<int> &Pa) {
  ll result = 0;
  for (int i : Pa) {
    result += i / val;
  }
  return result >= num;
}

int main() {
  int S, C;
  std::cin >> S >> C;

  std::vector<int> Pa(S);
  ll sum = 0;
  int max_len = 0;
  for (int i = 0; i < S; ++i) {
    std::cin >> Pa[i];
    sum += Pa[i];
    max_len = std::max(max_len, Pa[i]);
  }

  int left = 1, right = max_len, ans = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if(check(mid, C, Pa)) {
      ans = mid;
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }

  std::cout << (sum - static_cast<ll>(ans) * C) << '\n';
  return 0;
}