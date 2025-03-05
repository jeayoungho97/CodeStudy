#include<bits/stdc++.h>
using namespace std;
int N, M, result, visited[10004];
vector<int> tree[10004]; 
vector<int> ret;
int go(int node){
    visited[node] = 1;
    int cnt = 0;
    for(int i : tree[node]){
        if(visited[i]) continue;
        cnt += go(i);
    }
    return cnt + 1;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int child, parent;
        cin >> child >> parent;
        tree[parent].push_back(child);
    }
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        int a = go(i);
        if(a > result){
            ret.clear();
            ret.push_back(i);
            result = a;
        }
        else if(a == result){
            ret.push_back(i);
        }
    }
    sort(ret.begin(), ret.end());
    for(int i : ret) cout << i << " ";
    cout << "\n";
    return 0;
}