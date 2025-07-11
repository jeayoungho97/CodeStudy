#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  int n, max = -4001, min = 4001, sum = 0;
  std::cin >> n;

  std::vector<int> inputs;

  for (int i = 0; i < n; ++i) {
    int input;
    std::cin >> input;
    sum += input;

    inputs.push_back(input);
    max = std::max(max, input);
    min = std::min(min, input);
  }

  //산술 평균
  double sansul = (double)sum / n;
  int rounded_sansul = std::round(sansul);
  std::cout << rounded_sansul << '\n';

  //중앙값
  std::sort(inputs.begin(), inputs.end());
  int middle = inputs[n / 2];
  std::cout << middle << '\n';

  //최빈값
  std::vector<int> modes;
  int max_count = 1;
  int count = 1;
  for (int i = 1; i < inputs.size(); ++i) {
    if (inputs[i] == inputs[i - 1]) count++;
    else count = 1;

    if (count > max_count) {
      max_count = count;
      modes.clear();
      modes.push_back(inputs[i]);
    }
    else if (count == max_count) {
      modes.push_back(inputs[i]);
    }
  }

  if (max_count == 1) {
    modes.push_back(inputs[0]);
    std::sort(modes.begin(), modes.end());
  }

  if (modes.size() > 1) { 
    std::cout << modes[1] << '\n';
  }
  else {
    std::cout << modes[0] << '\n';
  }

  //범위
  int range = max - min;
  std::cout << range << '\n';

  return 0;
}