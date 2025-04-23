#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  long long result = 0;
  int left = 0, right = 0;
  
  bool visited[100001] = {};
  while (left < n) {

    while (!visited[v[right]] && right < n) {
      visited[v[right]] = true;
      ++right;
    }
    result += right - left;
    visited[v[left]] = false;
    ++left;
  }

  // 기존에 visited 와 right 를 매번 초기화하던 로직이 필요 없음.
  // 이전 left 에서 right 가 늘어났다는 것은 중복된 것이 없다는 뜻이므로
  // 그 right 와 visited 를 그대로 사용하고 이전 left 의 visited 만 false 처리해주면 됨.

  // 또한 result 에 매번 ++ 를 할 것이 아니라 right - left 계산 한번으로 하면 됨.

  std::cout << result << '\n';
  return 0;
}