#include<bits/stdc++.h>
using namespace std;

int N, M, J, cnt, p, l = 1, r;

void solve(int pos){
    r = l + (M - 1);
    if(pos >= l && pos <= r) return;
    else if(pos < l){
        cnt += (l - pos);
        l = pos;
        r = l + (M -1);
        return;
    }
    else{
        cnt += (pos - r);
        r = pos;
        l = r - (M - 1);
        return;
    }
}

int main(){
    cin >> N >> M;
    cin >> J;
    while(J--){
        cin >> p;
        solve(p);
    }
    cout << cnt << '\n';
    return 0;
}