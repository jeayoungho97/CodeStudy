#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N, ret;
vector<ll> result;
int main(){
    cin >> T;
    while(T--){
        ret = 0;
        cin >> N;
        while(N / 5 != 0){
            N /= 5;
            ret += N;
        }
        result.push_back(ret);
    }
    for(ll l : result) cout << l << '\n';
    return 0;
}
