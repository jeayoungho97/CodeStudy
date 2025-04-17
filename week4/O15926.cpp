#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<char> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  std::stack<char> stk = {};
  int result = 0;

  for (char ch : arr) {
    if (ch == '(') {
      stk.push(ch);
    }
    else {
      if (stk.empty()) {
        continue;
      }
      else {
        stk.pop();

      }
    }
  }

  return 0;
}