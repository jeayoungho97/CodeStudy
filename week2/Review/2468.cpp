#include<bits/stdc++.h>
using namespace std;

int Map[104][104], visited[104][104];
int ny, nx, x, y, N, h, result;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(visited[ny][nx] || Map[ny][nx] <= h) continue;
        DFS(ny,nx);
    }
    return;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
            h = max(h, Map[i][j]);
        }
    }
    while(h >= 0){
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && Map[i][j] > h){
                    DFS(i, j);
                    cnt++;    
                }
            }
        }
        result = max(result, cnt);
        h--;
    }
    cout << result << '\n';
    return 0;
}