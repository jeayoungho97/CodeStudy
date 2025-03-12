#include<bits/stdc++.h>
using namespace std;

int N, M, ny, nx, ret, visited[51][51];
char Map[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int BFS(int y, int x){
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(visited[ny][nx] || Map[ny][nx] == 'W') continue;
            q.push({ny,nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    return visited[y][x] - 1;
}

int main(){
    cin >> N >> M;
    cin.ignore();
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 'L'){
                ret = max(ret, BFS(i, j));
            }
        }
    }

    cout << ret << '\n';
    return 0;
}