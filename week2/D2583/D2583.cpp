#include<bits/stdc++.h>
using namespace std;
int cnt, m, n, k, ny, nx, a[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<int> ret;
void DFS(int y, int x){
    a[y][x] = 1;
    cnt++;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(a[ny][nx] == 1) continue;
        DFS(ny,nx);
    }
    return;
}
int main(){
    cin >> n >> m >> k;
    while(k--){
        int y1, y2, x1, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y = y1; y < y2; y++){
            for(int x = x1; x < x2; x++){
                a[y][x] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){
                DFS(i, j);
                ret.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << ret.size() << "\n";
    sort(ret.begin(), ret.end());
    for(int i : ret)cout << i << " ";
    cout << "\n";
    return 0;
}