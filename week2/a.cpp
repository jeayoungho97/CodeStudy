#include<bits/stdc++.h>
using namespace std;

int n, m, k, y, x, ny, nx, adj[51][51];
bool visited[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || adj[ny][nx] == 0)continue;
        if(adj[ny][nx] && !visited[ny][nx]){
            DFS(ny,nx);
        }
    }
    return;
}

int main(){
    int cases;
    cin >> cases;
    int ret[cases];
    for(int i = 0; i < cases; i++){
        fill(&adj[0][0], &adj[0][0] + 51*51, 0);            // (중요) 테스트 케이스를 돌릴 때마다 배열을 초기화해야함.
        fill(&visited[0][0], &visited[0][0] + 51*51, 0);
        ret[i] = 0;
        cin >> m >> n >> k;
        for(int j = 0; j < k; j++){
            int a,b;
            cin >> a >> b;
            adj[b][a] = 1;
        }
        for(int z = 0; z < n; z++){
            for(int w = 0; w < m; w++){
                if(!visited[z][w] && adj[z][w]){
                    ret[i]++; DFS(z, w);
                }
            }
        }
    }
    for(int i : ret) cout << i << "\n";
    return 0;
}