#include<bits/stdc++.h>
using namespace std;
#define y1 aaa
int N, M, K, y1, y2, x1, x2, ny, nx, cnt1, cnt2, visited[101][101], Map[101][101];
vector<int> result;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y, int x){
    visited[y][x] = 1;
    cnt2++;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] || Map[ny][nx]) continue;
        DFS(ny,nx);
    }
    return;
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++){
            for(int k = x1; k < x2; k++){
                Map[j][k] = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && Map[i][j] == 0){
                cnt1++;
                cnt2 = 0;
                DFS(i,j);
                result.push_back(cnt2);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << cnt1 << '\n';
    for(int i : result) cout << i << " ";
    cout << '\n';
    return 0;
}