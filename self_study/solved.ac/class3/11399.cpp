#include <iostream>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  int arr[1004];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + n);

  int psum[1004];
  psum[0] = arr[0];
  for (int i = 1; i < n; ++i) {
    psum[i] = psum[i - 1] + arr[i];
  }

  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += psum[i];
  }

  std::cout << ret << '\n';
  return 0;
}