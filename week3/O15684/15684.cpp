#include<bits/stdc++.h>
using namespace std;

int N, M, H, a, b, cnt;
vector<pair<int,int>> v[10];

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}

bool check(){
    for(int line = 1; line < 10; line++){
        sort(v[line].begin(), v[line].end(), cmp);
        stack<int> stk;
        for(int i : v[line].second){
            if(stk.size() && stk.top() == i) stk.pop();
            else stk.push(i);
        }
    }
    if(stk.size()) return false;
    return true;
}

int main(){
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        v[b].push_back({a,b});
        if(b != 1) v[b-1].push_back({a,b});
    }
    if(check()){
        cout << "YES\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}