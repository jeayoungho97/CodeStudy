#include <iostream>
#include <queue>
#include <string>

std::queue<int> que;

void go(std::string& order) {
  if (order == "push") {
    int temp;
    std::cin >> temp;
    que.push(temp);
  }

  if (order == "pop") {
    if (que.empty()) {
      std::cout << -1 << '\n';
    }
    else {
      std::cout << que.front() << '\n';
      que.pop();
    }
  }

  if (order == "size") {
    std::cout << que.size() << '\n';
  }

  if (order == "empty") {
    if (que.empty()) std::cout << 1 << '\n';
    else std::cout << 0 << '\n';
  }

  if (order == "front") {
    if (que.empty()) {
      std::cout << -1 << '\n';
    }
    else {
      std::cout << que.front() << '\n';
    }
  }

  if (order == "back") {
    if (que.empty()) {
      std::cout << -1 << '\n';
    }
    else {
      std::cout << que.back() << '\n';
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