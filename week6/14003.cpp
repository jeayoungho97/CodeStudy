#include <iostream>
#include <stack>
#include <vector>

const int INF = 1e9 + 4;

int n, num, len;
std::stack<int> stk;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::cin >> n;
  std::vector<int> lis(n);
  std::fill(lis.begin(), lis.end(), INF);

  std::vector<std::pair<int, int>> ans(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    auto lowerPos = std::lower_bound(lis.begin(), lis.end(), num);
    int pos = (int)(lowerPos - lis.begin());

    if (*lowerPos == INF) ++len;
    *lowerPos = num;

    ans[i].first = pos;
    ans[i].second = num;
  }

  std::cout << len << '\n';
  for (int i = n - 1; i >= 0; --i) {
    if (ans[i].first == len - 1) {
      stk.push(ans[i].second);
      --len;
    }
  }

  while(!stk.empty()) {
    std::cout << stk.top() << ' ';
    stk.pop();
  }
  std::cout << '\n';
  return 0;
}