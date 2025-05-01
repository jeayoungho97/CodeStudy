#include <iostream>
#include <vector>
#include <array>
#include <string>

int t;
std::vector<std::array<bool, 8>> gears;
std::vector<int> visited;
std::vector<bool> connected;

void dfs(int x, int turn) {
  int dx[2] = {-1, 1};
  for (int i = 0; i < 2; ++i) {
    int nx = x + dx[i];
    if (nx < 0 || nx >= t || visited[nx]) continue;

    if (i == 0 && connected[nx]) {
      visited[nx] = turn * -1;
      dfs(nx, turn * -1);
    }
    else if (i == 1 && connected[x]) {
      visited[nx] = turn * -1;
      dfs(nx, turn * -1);
    }
  }
  return;
}

void rotate() {
  for (int i = 0; i < t; ++i) {
    if (visited[i] == -1) {
      for (int j = 0; j < 7; ++j) {
        std::swap(gears[i][j], gears[i][j + 1]);
      }
    }

    if (visited[i] == 1) {
      for (int j = 7; j > 0; --j) {
        std::swap(gears[i][j], gears[i][j - 1]);
      }
    }
  }
}

int main() {
  std::cin >> t;
  gears.resize(t);
  visited.resize(t);
  connected.resize(t - 1);

  for (int i = 0; i < t; ++i) {
    std::string gear;
    std::cin >> gear;

    for (int j = 0; j < gear.size(); ++j) {
      if (gear[j] == '0') gears[i][j] = 0;
      else gears[i][j] = 1;
    }
  }

  int k;
  std::cin >> k;

  for (int i = 0; i < k; ++i) {
    std::fill(connected.begin(), connected.end(), false);
    std::fill(visited.begin(), visited.end(), 0);

    int idx, turn;
    std::cin >> idx >> turn;

    for (int i = 0; i + 1 < gears.size(); ++i) {
      if (gears[i][2] != gears[i + 1][6]) connected[i] = true;
    }

    visited[idx - 1] = turn;
    dfs(idx - 1, turn);

    rotate();
  }

  int result = 0;
  for (int i = 0; i < t; ++i) {
    if (gears[i][0]) ++result;
  }

  std::cout << result << '\n';
  return 0;
}

// gears.resize(t);
// 위 부분이 왜 필요하냐면...
// 전역변수로 gears 를 선언할 때 
// std::vector<std::array<bool, 8>> gears(t);
// 이렇게 하면 얼핏 가능한 것처럼 보이지만
// t 의 값을 아직 모르므로 선언자체가 불가능해짐. -> dummy variable 이 들어감.

// std::fill(connected.begin(), connected.end(), false);
// std::fill(visited.begin(), visited.end(), 0);
// 위 코드를 std::memset(&connected, 0, sizeof(connected)) 로 풀었다가 틀림
// WHY?
// connected 와 visited 는 벡터이므로 &connected 는 내부 배열의 시작주소가 아닌 벡터 객체 자체의 주소를 나타냄.
// + memset 이 할 수 있는 것은 거의 다 fill 이 할 수 있으므로 웬만하면 fill 을 쓰자.