#include <iostream>
#include <stack>
#include <string>

std::stack<int> stk;

void go(std::string& order) {
  if (order == "push") {
    int temp;
    std::cin >> temp;
    stk.push(temp);
  }

  if (order == "pop") {
    if (stk.empty()) {
      std::cout << -1 << '\n';
    }
    else {
      std::cout << stk.top() << '\n';
      stk.pop();
    }
  }

  if (order == "size") {
    std::cout << stk.size() << '\n';
  }

  if (order == "empty") {
    if (stk.empty()) {
      std::cout << 1 << '\n';
    }
    else {
      std::cout << 0 << '\n';
    }
  }

  if (order == "top") {
    if (stk.empty()) {
      std::cout << -1 << '\n';
    }
    else {
      std::cout << stk.top() << '\n';
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string order;
    std::cin >> order;
    go(order);
  }
  return 0;
}