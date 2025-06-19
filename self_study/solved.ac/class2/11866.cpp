#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::queue<int> q;

  for (int i = 1; i <= n; ++i) {
    q.push(i);
  }

  std::vector<int> ret;
  while (q.size()) {
    for (int i = 0; i < k - 1; ++i) {
      q.push(q.front());
      q.pop();
    }

    ret.push_back(q.front());
    q.pop();
  }

  std::string final_ret = "<";
  for (int i : ret) {
    final_ret += std::to_string(i) + ", ";
  }
  final_ret.pop_back();
  final_ret.pop_back();
  final_ret += ">\n";

  std::cout << final_ret;
  return 0;
}