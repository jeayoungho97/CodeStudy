#include<bits/stdc++.h>
using namespace std;

int N, L, R, ny, nx, flag, cnt, Map[51][51], visited[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int,int>> Union;

void DFS(int y, int x){
    visited[y][x] = 1;
    Union.push_back({y,x});
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
        int diff = abs(Map[ny][nx] - Map[y][x]);
        if(diff < L || diff > R ) continue;
        flag = 1;
        DFS(ny, nx);
    }
    return;
}


int main(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j];
        }
    }
    while(true){
        flag = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j]){
                    DFS(i,j);
                    if(Union.size() > 1){
                        int avg = accumulate(Union.begin(), Union.end(), 0, 
                                             [&](int acc, pair<int,int> p){return acc + Map[p.first][p.second];}) 
                                             / Union.size();
                        for(pair<int,int> p : Union){
                            Map[p.first][p.second] = avg;
                        }    
                    }
                    Union = {};
                }
            }
        }
        if(flag == 0) break;
        memset(visited, 0, sizeof(visited));
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}