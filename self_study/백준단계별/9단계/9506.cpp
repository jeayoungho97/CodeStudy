#include <iostream>
#include <vector>
#include <string>

int main() {
  while (true) {
    int N;
    std::cin >> N;
    if (N == -1) break;

    int sum = 0;
    std::vector<int> factors;

    for (int i = 1; i <= N / 2; ++i) {
      if (N % i == 0) {
        factors.push_back(i);
        sum += i;
      }
    }

    std::string result = std::to_string(N);

    if (sum == N) {
      result.append(" = ");
      for (int i = 0; i < factors.size(); ++i) {
        result.append(std::to_string(factors[i]));
        if (i + 1 != factors.size()) result.append(" + ");
      }
    }
    else {
      result.append(" is NOT perfect.");
    }
    
    std::cout << result << '\n';
  }

  return 0;
}