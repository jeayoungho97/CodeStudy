#include <iostream>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, l;
  std::cin >> n >> l;

  std::pair<int, int> pool[n];

  for (int i = 0; i < n; ++i) {
    int left, right;
    std::cin >> left >> right;
    pool[i] = {left, right};
  }
  
  std::sort(pool, pool + n);
  int end = 0;
  int result = 0;
  
  for (int i = 0; i < n; ++i) {
    int left = pool[i].first;
    int right = pool[i].second;

    if (end <= left) {
      end = left;
    }

    if (end < right) {
      int len = right - end;
      int count = (len + l - 1) / l;
      end += count * l;
      result += count;
    }
  }
  std::cout << result << '\n';
  return 0;
}

// end < right 
// 이 부분을 while 문으로 계속 end += l; 했었는데
// 그냥 계산하면 되는 거였다. -> 획기적 시간 단축
// ios_base::sync_with_stdio(false)
// 이거랑 암튼 입출력 최적화하니까 시간이 훨씬 단축됨.