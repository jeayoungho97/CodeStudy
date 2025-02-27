#include<bits/stdc++.h>
using namespace std;
const int n_max = 101;
int ret, depth, n, ny, nx, visited[n_max][n_max], a[n_max][n_max];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] <= depth) continue;
        if(visited[ny][nx]) continue;
        DFS(ny, nx);
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            depth = max(depth, a[i][j]);
        }
    }
    while(depth--){
        fill(&visited[0][0], &visited[0][0] + 101*101, 0);      
        // 초기화는 전체 2차원 배열을 다 해줘야함 ex. &visited[0][0] + 7*7 이런 식으로 하면 50개의 요소만 지워짐.
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > depth && !visited[i][j]){
                    cnt++; DFS(i, j);
                }
            }
        }
        ret = max(ret,cnt);
    }
    cout << ret << "\n";
    return 0;
}