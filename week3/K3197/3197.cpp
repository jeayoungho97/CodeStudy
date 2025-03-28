#include<bits/stdc++.h>
using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[1501][1501][2]; // 원본 맵을 훼손시키지 않기 위해?
bool flag = false;
char Map[1501][1501];
vector<pair<int,int>> swan;
queue<pair<int,int>> q;

void melt_ice(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx][0]) continue;

        visited[ny][nx][0] = true;

        if(Map[ny][nx] == '.'){
            melt_ice(ny, nx);
        } 
        else {
            q.push({ny, nx});
        }
    }
}

void find_swan(int y, int x){
    visited[y][x][1] = true;
    if(y == swan[1].first && x == swan[1].second) flag = true;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx][1] || !visited[ny][nx][0]) continue;
        find_swan(ny, nx);
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'L') {
                swan.push_back({i, j});
                visited[i][j][0] = true;
            }
        }
    }

    for(auto [y, x] : swan){
        q.push({y, x});
    }  

    int step = 0;

    while(!q.empty()){
        fill(&visited[0][0][1], &visited[0][0][1] + 1501*1501, false);
        auto [sy, sx] = swan[0];
        
        find_swan(sy, sx);

        if(flag){
            cout << step << '\n';
            return 0;
        }
        step++;
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            auto [y, x] = q.front(); q.pop();
            melt_ice(y, x);
        }
    }

    return 0;
}