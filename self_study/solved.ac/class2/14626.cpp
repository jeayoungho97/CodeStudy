#include <iostream>
#include <string>

int main() {
  std::string temp;
  std::cin >> temp;

  int sum = 0, idx;
  for (int i = 0; i < 13; ++i) {
    if (temp[i] == '*') {
      idx = i;
    }
    else {
      int num = temp[i] - '0';
      sum += (i % 2 == 0) ? num : 3 * num;
    }
  }
  int ret;
  for (ret = 0; ret < 10; ++ret) {
    if (idx % 2 == 0) {
      if ((sum + ret) % 10 == 0) break;
    }
    else {
      if ((sum + ret * 3) % 10 == 0) break;
    }
  }

  std::cout << ret << '\n';
  return 0;
}