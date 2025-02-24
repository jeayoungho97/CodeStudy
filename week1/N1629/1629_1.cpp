#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
ll go(ll a, ll b){
    if(b==1) return a % c;       // 초기 ret 값인 a % c 가 나옴.

    ll ret = go(a, b/2);         // b == 1 일때까지 쭈욱 내려감.
    ret = (ret * ret) % c;       // b == 1 이후엔 쭈욱 밑의 논리가 반복됨.
    if(b % 2)ret = (ret * a)%c;  // b 가 홀수일 땐 나머지 한 번 더 계산해줌.
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a,b) << "\n";
    return 0;
}