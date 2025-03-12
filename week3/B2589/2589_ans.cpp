#include<bits/stdc++.h>
using namespace std; 
int n, m, mx, visited[54][54]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
char a[54][54];
void bfs(int y, int x){
    memset(visited, 0, sizeof(visited)); 
    visited[y][x] = 1; 
    queue<pair<int, int>> q; 
    q.push({y, x}); 
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; 
            if(visited[ny][nx]) continue; 
            if(a[ny][nx] == 'W')continue;
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
            // max 값을 구할 필요 없이 while 문이 끝난 이후의 y, x 가 마지막으로 가장 먼 거리의 좌표를 의미함.
        }
    }
    return;
}
int main(){
    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j]; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L') bfs(i, j); 
        }
    } 
    cout << mx - 1 << "\n";
}