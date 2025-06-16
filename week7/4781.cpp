#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int go(int money, const std::vector<std::pair<int, int>>& items, std::vector<int>& dp) {
  int &ret = dp[money];
  if (ret != -1) return ret;

  bool flag = false;

  for (int i = 0; i < items.size(); ++i) {
    auto item = items[i];
    if (money < item.second) continue;

    ret = std::max(ret, item.first + go(money - item.second, items, dp));
    flag = true;
  }

  if (flag) return ret;
  else return 0;
}


int main() {
  while (true) {
    int n;
    double temp_m;
    std::cin >> n >> temp_m;
    int money = std::round(temp_m * 100);
    if (n == 0 && money == 0) {
      break;
    }

    std::vector<int> dp(money + 1, -1);
    std::vector<std::pair<int, int>> items(n); 
    for (int i = 0; i < n; ++i) {
      int calorie;
      double temp_p;
      std::cin >> calorie >> temp_p;
      int price = std::round(temp_p * 100);

      items[i] = {calorie, price};
    }

    int ret = go(money, items, dp);
    std::cout << ret << '\n';
  }


  return 0;
}
