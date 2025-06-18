#include <iostream>
#include <stack>

int main() {
  int k;
  std::cin >> k;

  std::stack<int> stk;
  for (int i = 0 ; i < k; ++i) {
    int temp;
    std::cin >> temp;
    if (stk.size() && temp == 0) {
      stk.pop();
    }
    else {
      stk.push(temp);
    }
  }

  int ret = 0;
  while (stk.size()) {
    ret += stk.top();
    stk.pop();
  }

  std::cout << ret << '\n';
  return 0;
}