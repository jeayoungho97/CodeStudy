#include<bits/stdc++.h>
using namespace std;

int N, M, cnt, swanY, swanX;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int,int>> swan;
char Map[1501][1501];
bool visited[1501][1501];
bool visited_swan[1501][1501];
queue<pair<int,int>> water_q, next_water_q;
queue<pair<int,int>> swan_q, next_swan_q;


bool find_swan(){
    while(swan_q.size()){
        auto [y, x] = swan_q.front(); swan_q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(visited_swan[ny][nx]) continue;

            visited_swan[ny][nx] = true;

            if(Map[ny][nx] == '.'){
                swan_q.push({ny, nx});
            }
            else if(Map[ny][nx] == 'X'){
                next_swan_q.push({ny, nx});
            }
            else if(Map[ny][nx] == 'L') return true;
        }
    }
    return false;
}

void melt_ice(){
    while(water_q.size()){
        auto [y, x] = water_q.front(); water_q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;

            if(Map[ny][nx] == 'X'){
                Map[ny][nx] = '.';
                next_water_q.push({ny, nx});
            }
            else{
                water_q.push({ny,nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'L') {
                swanY = i, swanX = j;
            }
            if(Map[i][j] != 'X') {
                water_q.push({i, j}); 
                visited[i][j] = true;
            }
        }
    }
    swan_q.push({swanY, swanX});
    visited_swan[swanY][swanX] = true;
    while(true){
        if(find_swan()){
            cout << cnt << '\n';
            return 0;
        }
        melt_ice();
        water_q = next_water_q;
        swan_q = next_swan_q;
        next_water_q = queue<pair<int,int>> ();
        next_swan_q = queue<pair<int,int>> ();
        cnt++;
    }

    return 0;
}