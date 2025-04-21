#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int main() {
  std::string s, t, result = "";
  std::cin >> s >> t;
  std::stack<char> stk;

  for (char ch : s) {
    stk.push(ch);

    if (stk.size() >= t.size() && stk.top() == t[t.size() - 1]) {
      std::string ss = "";

      for (char i : t) {
        ss += stk.top();
        stk.pop();
      }

      std::reverse(ss.begin(), ss.end());
      if (ss != t) {
        for (char j : ss) {
          stk.push(j);
        }
      }

    }
  }

  if (stk.empty()) {
    std::cout << "FRULA\n";
  } 
  else {
    while (!stk.empty()) {
      result += stk.top();
      stk.pop();
    }
    std::reverse(result.begin(), result.end());
    std::cout << result << '\n';
  }

  return 0;
}