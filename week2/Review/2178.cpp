#include <bits/stdc++.h>
using namespace std;
int Map[104][104], visited[104][104];
int y, x, ny, nx, N, M;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void BFS(){
    while(q.size()){
        tie(y, x) = q.front(); 
        q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(visited[ny][nx] || Map[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    return;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &Map[i][j]);
        }
    }
    q.push({0,0});
    visited[0][0] = 1;
    BFS();
    printf("%d\n", visited[N-1][M-1]);
    return 0;
}