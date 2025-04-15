#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

std::vector<std::string> result;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t;
  std::cin >> t;

  while (t--) {
    // input phase
    std::string op, num;
    int n;
    std::cin >> op;
    std::cin >> n;
    std::cin >> num;
    
    // D 개수와 n 비교하기
    if (std::count(op.begin(), op.end(), 'D') > n) {
      result.push_back("error");
      continue;
    }
    
    // [1,2,3,4] -> 배열로 변환
    std::deque<int> arr;
    std::string temp;
    for (char ch : num) {
      if (std::isdigit(ch)) {
        temp += ch;
      } else if (!temp.empty()) {
        arr.push_back(std::atoi(temp.c_str()));
        temp.clear();
      }
    }

    bool flag = false;
    bool reversed = false;

    // operate phase
    for (char ch : op) {
      if (ch == 'R') {
        reversed ^= 1;
      }
      else {
        if(reversed) arr.pop_back();
        else arr.pop_front();
      }
    }

    // 결과를 출력
    std::string output = "[";

    if (reversed) {
      for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        output += std::to_string(*it);
        output += ',';
      }
    } else {
      for (auto it = arr.begin(); it != arr.end(); ++it) {
        output += std::to_string(*it);
        output += ',';
      }
    }

    if (!arr.empty()) output.pop_back();

    output += ']';
    result.push_back(output);
  }
  for (std::string str : result) {
    std::cout << str << '\n';
  }
  return 0;
}