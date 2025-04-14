#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

constexpr int dy[4] = {0, -1, 0, 1}; // 서-북-동-남
constexpr int dx[4] = {-1, 0, 1, 0};

int n, m;
int map[51][51];
int room_id[51][51];      // 각 칸의 방 번호
int room_size[2501];      // 방 번호 -> 크기
bool visited[51][51];

int num_room = 0;
int max_room = 0;
int max_room_after = 0;

int dfs(int y, int x, int id) {
    visited[y][x] = true;
    room_id[y][x] = id;
    int size = 1;

    for (int i = 0; i < 4; ++i) {
        if (!(map[y][x] & (1 << i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx]) continue;

            size += dfs(ny, nx, id);
        }
    }

    return size;
}

int main() {
    std::cin >> m >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> map[i][j];

    // 1. 방 번호 붙이고 크기 저장
    std::memset(visited, 0, sizeof(visited));
    int id = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                int size = dfs(i, j, id);
                room_size[id] = size;
                max_room = std::max(max_room, size);
                id++;
            }
        }
    }

    num_room = id - 1;

    // 2. 벽 하나 제거 시 최댓값 계산
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cur_id = room_id[i][j];
            for (int d = 0; d < 4; ++d) {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                if (map[i][j] & (1 << d)) { // 벽이 있는 방향만 체크
                    int next_id = room_id[ny][nx];
                    if (cur_id != next_id) {
                        int combined = room_size[cur_id] + room_size[next_id];
                        max_room_after = std::max(max_room_after, combined);
                    }
                }
            }
        }
    }

    std::cout << num_room << '\n';
    std::cout << max_room << '\n';
    std::cout << max_room_after << '\n';

    return 0;
}
