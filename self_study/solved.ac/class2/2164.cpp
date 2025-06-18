#include <iostream>
#include <queue>

int main() {
  std::queue<int> deck;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    deck.push(i + 1);
  }

  while (deck.size() != 1) {
    deck.pop();
    int temp = deck.front();
    deck.push(temp);
    deck.pop();
  }

  std::cout << deck.front() << '\n';
  return 0;
}