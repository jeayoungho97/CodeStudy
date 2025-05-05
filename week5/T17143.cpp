#include <iostream>

int R, C, M, result;

struct data {
  int s, d, z;
};

data A[101][101], B[101][101];
data (*map)[101] = A;
data (*next_map)[101] = B;

void go(int x){
  for (int i = 0; i < R; ++i) {
    if (map[i][x].z) {
      result += map[i][x].z;
      map[i][x] = {0, 0, 0};
      break;
    }
  }

  std::fill(&next_map[0][0], &next_map[0][0] + 101 * 101, data{0,0,0});

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      int y = i;
      int x = j;
      data here = map[i][j];
      int s = here.s;
      int d = here.d;
      int z = here.z;

      if (z == 0) continue;

      if (d <= 2) {
        int cycle = 2 * (R - 1);
        s %= cycle;

        if (d == 1) y -= s;
        else        y += s;

        while (y < 0 || y >= R) {
          if (y < 0) {y = -y; d = 2;}
          else if (y >= R) {y = 2 * (R - 1) - y; d = 1;}
        }
      }
      else {
        int cycle = 2 * (C - 1);
        s %= cycle;
        
        if (d == 4) x -= s;
        else        x += s;

        while (x < 0 || x >= C) {
          if (x < 0) {x = -x; d = 3;}
          else if (x >= C) {x = 2 * (C - 1) - x; d = 4;}
        }
      }

      if (next_map[y][x].z < z) {
        next_map[y][x] = {s, d, z};
      }
    
    }
  }

  std::swap(map, next_map);
}

// void check_map() {
//   std::cout << "------------------------\n";
//   for (int i = 0; i < R; ++i) {
//     for (int j = 0; j < C; ++j) {
//       std::cout << map[i][j].z << ' ';
//     }
//     std::cout << '\n';
//   }
//   std::cout << "------------------------\n";
//   return;
// }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> R >> C >> M;
  for (int i = 0; i < M; ++i) {
    int y, x, speed, dir, size;
    std::cin >> y >> x >> speed >> dir >> size;
    map[y - 1][x - 1] = {speed, dir, size};
  }

  // check_map();

  for (int i = 0; i < C; ++i) {
    go(i);
    // check_map();
  }
  std::cout << result << '\n';

  return 0;
}