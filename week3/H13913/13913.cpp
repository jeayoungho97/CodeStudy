#include<bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
int N, K, ret;
int visited[100001], prev[100001];
int cnt;

void BFS(){
    queue<int> q;
    q.push(N);
    visited[N] = 1;

    while(!q.empty()){
        int here = q.front();
        q.pop();
        if(here == K){
            if(ret == 0){
                ret = visited[here] - 1;
                break;
            } 
        }

        for(int next : {here - 1, here + 1, here * 2}){
            if(next < 0 || next > 100000) continue;
            if(!visited[next]){
                q.push(next);
                visited[next] = visited[here] + 1;
                prev[next] = here;
            }
        }
    }
}

int main(){
    cin >> N >> K;
    BFS();
    vector<int> v;
    for(int i = K; i != N; i = prev[i]){
        v.push_back(i);
    }
    v.push_back(N);
    reverse(v.begin(), v.end());

    cout << ret << '\n';
    for(int i : v) cout << i << " ";
    return 0;
}