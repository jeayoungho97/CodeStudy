#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  int result = 0, left = 0;

  while (left < n) {
    int right = left;
    bool visited[100001] = {};

    while (!visited[v[right]] && right < n) {
      visited[v[right]] = true;
      ++right;
      ++result;
    }

    ++left;
  }

  std::cout << result << '\n';
  return 0;
}