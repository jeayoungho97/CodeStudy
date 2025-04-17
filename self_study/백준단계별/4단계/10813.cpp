#include <iostream>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i + 1;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    std::swap(arr[a - 1], arr[b - 1]);
  }

  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << '\n';
  return 0;
}