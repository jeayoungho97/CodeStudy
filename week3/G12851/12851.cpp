#include<bits/stdc++.h>
using namespace std;
int N, K, cnt, Min = 100000;
int visited[100000];
// 결과들을 담아놓는 벡터
vector<int> ret;

void solve(int N, int cnt){
    if(N < 0 || N > 100000) return;
    if(visited[N] && cnt > visited[N]) return;
    visited[N] = cnt;
    if(N == K){
        ret.push_back(cnt);
        Min = min(cnt, Min);
    }
    if(N < K){
        solve(N + 1, cnt + 1);
        solve(2 * N, cnt + 1);
        solve(N - 1, cnt + 1);
    }
    if(N > K){
        solve(N - 1, cnt + 1);
    }
}

int main(){
    cin >> N >> K;
    solve(N, 0);
    for(int i : ret){
        if(i == Min) cnt++;
    }
    cout << Min << '\n';
    cout << cnt << '\n';
    return 0;
}