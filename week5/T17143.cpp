#include <iostream>
#include <vector>

int R, C, M, result;
std::vector<bool> shark_removed;
std::pair<int, int> visited[101][101]; // size, index of shark

struct shark {
  std::pair<int, int> pos;
  int speed;
  int direction;
  int size;
  int index;
};

std::vector<shark> sharks;

void move_shark(int idx) {
  shark a = sharks[idx];
  int sum = (a.direction <= 2) ? a.pos.first + a.speed : a.pos.second + a.speed;
  bool switch_lr = (sum / (C - 1)) % 2;
  bool switch_ud = (sum / (R - 1)) % 2;
  switch(a.direction) {
    case 1 :
    if (switch_ud) {
      a.direction = 2;
      a.pos.first = sum % (R - 1);
    }
    else {
      a.pos.first = (R - 1) - (sum % (R - 1));
    }
    break;

    case 2 :
    if (switch_ud) {
      a.direction = 1;
      a.pos.first = (R - 1) - (sum % (R - 1));
    }
    else {
      a.pos.first = sum % (R - 1);
    }
    break;

    case 3 :
    if (switch_lr) {
      a.direction = 4;
      a.pos.second = (C - 1) - (sum % (C - 1));
    }
    else {
      a.pos.second = sum % (C - 1);
    }
    break;

    case 4 :
    if (switch_lr) {
      a.direction = 3;
      a.pos.second = sum % (C - 1);
    }
    else {
      a.pos.second = (C - 1) - (sum % (C - 1));
    }
    break;
  }

  // 상어끼리 사냥시키기
  std::pair<int, int> og_shark = visited[a.pos.first][a.pos.second];
  if(og_shark.first < a.size) {
    shark_removed[og_shark.second] = true;
    visited[a.pos.first][a.pos.second] = {a.size, idx};
  }
  else {
    shark_removed[idx] = true;
  }
}

void go(int x) {
  std::fill(&visited[0][0], &visited[0][0] + 101 * 101, std::pair<int,int> {0, 0});

  // 제거할 상어 찾기
  int closest = R;
  int idx_to_remove = -1;
  for (int i = 0; i < sharks.size(); ++i) {
    // 이미 제거된 상어는 건너뛰기
    if (shark_removed[i]) continue;

    std::pair<int, int> position = sharks[i].pos;
    if (position.second == x && position.first < closest) {
      closest = position.first;
      idx_to_remove = i;
    }
  }

  if (idx_to_remove != -1) {
    result += sharks[idx_to_remove].size;
    shark_removed[idx_to_remove] = true;
  }

  for (int i = 0; i < sharks.size(); ++i) {
    if (shark_removed[i]) continue;
    move_shark(i);
  }
}

int main() {
  std::cin >> R >> C >> M;

  shark_removed.resize(M);
  std::fill(shark_removed.begin(), shark_removed.end(), false);

  for (int i = 0; i < M; ++i) {
    shark a;
    std::cin >> a.pos.first >> a.pos.second >> a.speed >> a.direction >> a.size;
    a.index = i;
    sharks.push_back(a);
  }

  for (int i = 0; i < C; ++i) go(i);


  std::cout << result << '\n';
  return 0;
}