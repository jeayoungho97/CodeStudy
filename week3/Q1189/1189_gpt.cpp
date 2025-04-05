#include <bits/stdc++.h>
using namespace std;

int R, C, K, ret[30];
char Map[6][6];
bool visited[6][6];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void showmap(){
    cout << "---------\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(visited[i][j]) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
}

void DFS(int y, int x, int cnt) {
    showmap();
    if (y == R - 1 && x == C - 1) {
        ret[cnt]++;
        cout << cnt << " is added" << '\n';
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (Map[ny][nx] == 'T' || visited[ny][nx]) continue;

        visited[ny][nx] = true;
        DFS(ny, nx, cnt + 1);
        visited[ny][nx] = false;
    }
}

int main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Map[i][j];
        }
    }

    visited[0][0] = true; // 시작점 방문 표시
    DFS(0, 0, 1);         // 시작점부터 cnt=1로 시작
    cout << ret[K] << '\n';
    return 0;
}
