#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
const ll INF = 9876543210;
int N;
ll Max = -INF, Min = INF;
std::vector<ll> numbers;
std::vector<int> operations;

void DFS(int count, ll result) {
  if (count == N - 1) {
    Max = std::max(result, Max);
    Min = std::min(result, Min);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    if (operations[i] == 0) continue;
    --operations[i];
    int next;

    if (i == 0) next = result + numbers[count + 1];
    if (i == 1) next = result - numbers[count + 1];
    if (i == 2) next = result * numbers[count + 1];
    if (i == 3) next = result / numbers[count + 1];

    DFS(count + 1, next);
    ++operations[i];
  }

}


int main() {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    ll num;
    std::cin >> num;
    numbers.push_back(num);
  }

  for (int i = 0; i < 4; ++i) {
    int op;
    std::cin >> op;
    operations.push_back(op);
  }

  DFS(0, numbers[0]);

  std::cout << Max << '\n' << Min << '\n';
  return 0;
}