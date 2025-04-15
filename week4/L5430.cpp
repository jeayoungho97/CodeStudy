#include <iostream>
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

    // RR 지우기
    size_t pos;
    std::string to_remove = "RR";
    while ((pos = op.find(to_remove)) != std::string::npos) {
      op.erase(pos, to_remove.length());
    }

    // D 개수와 n 비교하기
    if (std::count(op.begin(), op.end(), 'D') > n) {
      result.push_back("error");
      continue;
    }
    
    // [1,2,3,4] -> 배열로 변환
    std::vector<int> arr;
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

    // operate phase
    for (char ch : op) {
      if (ch == 'R') {
        std::reverse(arr.begin(), arr.end());
      }
      else {
        if (arr.empty()) {
          result.push_back("error");
          flag = true;
          break;
        }
        arr.erase(arr.begin());
      }
    }

    // 배열이 살아있는 경우 결과를 출력
    if (!flag) {
      std::string temp = "[";
      for (int i : arr) {
        temp += std::to_string(i);
        temp += ',';
      }
      temp.pop_back();
      temp += ']';
      result.push_back(temp);
    }
  }
  for (std::string str : result) {
    std::cout << str << '\n';
  }
  return 0;
}