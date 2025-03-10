#include <bits/stdc++.h>
using namespace std;

int a, cnt, ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> a){
        ret = 1;
        cnt = 1;
        while(ret % a != 0){
            ret = (ret * 10 + 1) % a;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}