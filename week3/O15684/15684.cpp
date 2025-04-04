#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N, M, H, a, b, ret = INF;
bool visited[31][11];

bool check(){
    for(int i = 1; i < N; i++){
        stack<int> stk;
        for(int j = 0; j < H; j++){
            if(stk.size()){
                int t = stk.top();
                if(visited[j][i]){
                    if(t == i) stk.pop();
                    else stk.push(i);
                }
                if(visited[j][i - 1]){
                    if(t == i - 1) stk.pop();
                    else stk.push(i - 1);
                }
            }
            else{
                if(visited[j][i]) stk.push(i);
                if(visited[j][i - 1]) stk.push(i - 1);
            }
        }
        if(!stk.empty()) return false;
    }
    return true;
}

void go(int row, int cnt){
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        ret = min(ret, cnt);
        return;
    }
    for(int i = row; i <= H; i++){
        for(int j = 1; j < N; j++){
            if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
            visited[i][j] = true;
            go(i, cnt + 1);
            visited[i][j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        visited[a][b] = true;
    }
    go(1, 0);
    cout << ((ret == INF) ? -1 : ret) << "\n";
    return 0;
}