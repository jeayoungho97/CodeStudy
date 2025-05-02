#include <iostream>

int moves[10];
int sum, result;

struct horse {
  int pos = 0;
  int route_num = 0;

  bool operator==(const horse& other) const {
    return route_num == other.route_num && pos == other.pos;
  }
};

horse horses[4];

int Move(int i, int move) {
  switch (horses[i].route_num) {
    case 0 :
      horses[i].pos += 2 * move;
      if (horses[i].pos % 10 == 0) horses[i].route_num = horses[i].pos / 10;
      break;

    case 1 :
      horses[i].pos += 3 * move;
      if (horses[i].pos > 19) {
        int move_left = (horses[i].pos - 22) / 3;
        horses[i].pos = 25;
        horses[i].route_num = 4;
        horses[i].pos = Move(i, move_left);
      }
      break;

    case 2 :
      horses[i].pos += 2 * move;
      if (horses[i].pos > 24) {
        int move_left = (horses[i].pos - 26) / 2;
        horses[i].pos = 25;
        horses[i].route_num = 4;
        horses[i].pos = Move(i, move_left);
      }
      break;

    case 3 :
      if (horses[i].pos == 30) {
        horses[i].pos = 29 - move;
      }
      else {
        horses[i].pos -= move;
      }

      if (horses[i].pos < 26) {
        int move_left = 25 - horses[i].pos; 
        horses[i].pos = 25;
        horses[i].route_num = 4;
        horses[i].pos = Move(i, move_left);
      }

      break;

    case 4 :
      horses[i].pos += 5 * move;
      break;
  }

  return horses[i].pos;
}

void go(int idx) {
  if (idx > 9) {
    result = std::max(result, sum);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    // 이미 도착한 말은 건너뜀
    if (horses[i].pos > 40) continue;

    horse prev = horses[i];
    int moved = Move(i, moves[idx]);

    if (moved > 40) {
      go(idx + 1);
      horses[i] = prev;
    }
    else {
      // 말의 도착지점에 다른 말이 있는지 확인
      bool flag = false;
      for (int j = 0; j < 4; ++j) {
        if (i != j && (horses[i] == horses[j])) {
          flag = true;
          break;
        }
      }
      
      if (flag) {
        horses[i] = prev;
        continue;
      }
  
      sum += moved;
  
      go(idx + 1);
  
      horses[i] = prev; // Back tracking
  
      sum -= moved;
    }
  }
}


int main() {
  for (int i = 0; i < 10; ++i) {
    std::cin >> moves[i];
  }

  go(0);

  std::cout << result << '\n';

  return 0;
}