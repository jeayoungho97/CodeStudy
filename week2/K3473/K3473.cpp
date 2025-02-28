#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N;
vector<ll> result;
void divide(ll N){
    ll ret = 0;
    while(N > 0){
        N = N/5;
        ret += N;
    }
    result.push_back(ret);
}

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        divide(N);
    }
    for(ll i : result) cout << i << "\n";
    return 0;
}