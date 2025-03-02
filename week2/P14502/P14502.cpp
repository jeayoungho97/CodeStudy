#include<bits/stdc++.h>
using namespace std;

int N, M, temp, ny, nx, cnt, Map[8][8], visited[8][8];
int Safe[70];
vector<int> v;
vector<pair<int,int>> Virus;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y, int x){
    visited[y][x] = 2;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx]) continue;
        DFS(ny, nx);
    }
}

void Combi(int start){
    if(v.size() == 3){
        copy(&Map[0][0], &Map[0][0] + 8 * 8, &visited[0][0]);
        for(int i : v){
            visited[i / M][i % M] = 1;
        }
        for(pair p : Virus){
            DFS(p.first, p.second);
        }
        temp = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visited[i][j] == 0)temp++;
            }
        }
        cnt = max(cnt, temp);
        return;
    }
    for(int i = start; i < 70; i++){
        if(Safe[i] == 1){
           v.push_back(i);
           Combi(i + 1);
           v.pop_back(); 
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> temp;
            Map[i][j] = temp;
            if(temp == 0) Safe[i * M + j] = 1;
            if(temp == 2) Virus.push_back({i,j});
        }
    }

    Combi(0);
    cout << cnt << "\n";
    return 0;
}