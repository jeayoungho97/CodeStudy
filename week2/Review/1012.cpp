#include<bits/stdc++.h>
using namespace std;

const int N_max = 50, M_max = 50;
int Map[N_max][M_max];
int testcase, N, M, K, y, x, ny, nx, cnt;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<int> result;

void DFS(int y, int x){
    Map[y][x] = 0;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(!Map[ny][nx]) continue;
        DFS(ny, nx);
    }
    return;
}


int main(){
    cin >> testcase;
    while(testcase--){
        // initializing testcase
        memset(Map, 0, sizeof(Map));
        cnt = 0;
        // taking input
        cin >> N >> M >> K;
        for(int i = 0; i < K; i++){
            cin >> y >> x;
            Map[y][x] = 1;
        }
        // Running DFS
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == 1){
                    cnt++;
                    DFS(i,j);
                }
            }
        }
        result.push_back(cnt);

    }
    for(int i : result) cout << i << '\n';
    return 0;
}