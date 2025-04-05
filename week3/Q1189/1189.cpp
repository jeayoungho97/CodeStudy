#include<bits/stdc++.h>
using namespace std;

int R, C, K, ret;
char Map[5][5];
bool visited[5][5];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void DFS(int y, int x, int cnt){
    if(y == 0 && x == C - 1){
        if(cnt == K) ret++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || Map[ny][nx] == 'T') continue;

        visited[ny][nx] = true;
        DFS(ny, nx, cnt + 1);
        visited[ny][nx] = false;
    }
    return;
}

int main(){
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> Map[i][j];
        }
    }
    visited[R - 1][0] = true;
    DFS(R - 1, 0, 1);
    cout << ret << '\n';
    return 0;
}