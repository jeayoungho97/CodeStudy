#include<bits/stdc++.h>
using namespace std;

int a[9], sum;
vector<int> v;
pair<int, int> ret;
void solve(){
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(sum - a[i] - a[j] == 100){
                ret ={i, j};
                return;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        cin >> a[i]; sum += a[i];
    }
    solve();
    for(int i = 0; i < 9; i++){
        if(ret.first == i || ret.second == i) continue;
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    for(int i : v) cout << i << "\n";
    return 0;
}