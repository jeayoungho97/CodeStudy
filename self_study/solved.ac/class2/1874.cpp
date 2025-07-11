#include <iostream>
#include <stack>
#include <vector>

int main() {
  int n, curr_max = 0;
  std::cin >> n;

  std::stack<int> stk;
  std::vector<char> result;
  bool flag = false;

  for (int i = 0; i < n; ++i) {
    int input;
    std::cin >> input;
     
    if (flag) continue;

    if (input > curr_max) {
      for (int j = curr_max + 1; j <= input; ++j) {
        stk.push(j);
        result.push_back('+');
      }
      curr_max = input;
    }
    
    if (stk.top() > input) {
      flag = true;
      continue;
    }

    stk.pop();
    result.push_back('-');
  }

  if (flag) {
    std::cout << "NO\n";
  }
  else {
    for (char ch : result) std::cout << ch << '\n';
  }

  return 0;
}