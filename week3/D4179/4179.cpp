#include<bits/stdc++.h>
using namespace std;

int R, C, ny, nx, visited[1004][1004], fire[1004][1004];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
char Map[1004][1004];
pair<int,int> J_pos;
vector<pair<int,int>> F_pos;

int BFS(){
    queue<pair<int,int>> q;
    q.push(J_pos);
    visited[J_pos.first][J_pos.second] = 1;
    while(q.size()){
        auto [y,x] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C) return visited[y][x];
            if(visited[ny][nx] || Map[ny][nx] != '.') continue;
            if(fire[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    return -1;
}

void BFS_fire(){ // BTS 의 fire 아님.
    queue<pair<int,int>> q;
    for(auto p : F_pos){
        q.push(p);
        fire[p.first][p.second] = 1;
    }

    while(q.size()){
        auto [y,x] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if(fire[ny][nx] != 1e9 || Map[ny][nx] != '.') continue;
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny,nx});
        }
    }
    return;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'J') J_pos = {i,j};
            if(Map[i][j] == 'F') F_pos.push_back({i,j});
        }
    }
    
    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, 1e9);

    
    BFS_fire();
    int ret = BFS();

    if(ret == -1) cout << "IMPOSSIBLE\n";
    else cout << ret << '\n';

    return 0;
}