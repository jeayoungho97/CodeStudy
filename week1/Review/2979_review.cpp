#include<bits/stdc++.h>
using namespace std;
int A, B, C, result, cnt[104];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> A >> B >> C;
    for(int i = 0; i < 3; i++){
        int t1, t2;
        cin >> t1 >> t2;
        for(int i = t1; i < t2; i++){
            cnt[i]++;
        }
    }
    for(int i = 1; i <= 100; i++){
        if(cnt[i] == 1) result += A;
        if(cnt[i] == 2) result += 2 * B;
        if(cnt[i] == 3) result += 3 * C;
    }
    cout << result << '\n';
    return 0;
}