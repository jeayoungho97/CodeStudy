#include <iostream>
#include <vector>

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> cards;
  for (int i = 0; i < N; ++i) {
    int card;
    std::cin >> card;
    cards.push_back(card);
  }

  int result = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int  k = j + 1; k < N; ++k) {
        int sum = cards[i] + cards[j] + cards[k];
        if (sum <= M && sum > result) {
          result = sum;
        }
      }
    }
  }

  std::cout << result << '\n';
  return 0;
}