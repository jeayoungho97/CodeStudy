#include<bits/stdc++.h>
using namespace std;
int n, k, cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){    
        cnt = 1;
        k = 1;
        while(k % n != 0){
            cnt++;
            k = (k * 10 + 1) % n;
        }
        cout << cnt << "\n";
    }
    return 0;
}