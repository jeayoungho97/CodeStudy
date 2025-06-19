// #include <iostream>
// #include <queue>
// #include <vector>

// int main() {
//   int n, k;
//   std::cin >> n >> k;

//   std::queue<int> q;

//   for (int i = 1; i <= n; ++i) {
//     q.push(i);
//   }

//   std::vector<int> ret;
//   while (q.size()) {
//     for (int i = 0; i < k - 1; ++i) {
//       q.push(q.front());
//       q.pop();
//     }

//     ret.push_back(q.front());
//     q.pop();
//   }

//   std::string final_ret = "<";
//   for (int i : ret) {
//     final_ret += std::to_string(i) + ", ";
//   }
//   final_ret.pop_back();
//   final_ret.pop_back();
//   final_ret += ">\n";

//   std::cout << final_ret;
//   return 0;
// }

#include <iostream>
#include <list>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::list<int> l;
  for (int i = 1; i <= n; ++i) {
    l.push_back(i);
  }

  std::vector<int> result;
  auto it = l.begin();

  while(!l.empty()) {
    for (int i = 0; i < k - 1; ++i) {
      ++it;
      if (it == l.end()) it = l.begin();
    }

    result.push_back(*it);
    it = l.erase(it);
    if (it == l.end()) it = l.begin();
  }

  std::cout << "<";
  for (int i = 0; i < result.size(); ++i) {
    std::cout << result[i];
    if (i != result.size() - 1) std::cout << ", ";
  }
  std::cout << ">\n";

  return 0;
}