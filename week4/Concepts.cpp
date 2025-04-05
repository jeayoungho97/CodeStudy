#include<bits/stdc++.h>
using namespace std;

int main(){
    // idx 번째 비트 끄기
    int S = 23; // 10111
    int idx = 1;
    S &= ~(1 << idx); // 10101 = 21
    cout << S << '\n';

    // idx 번째 비트 켜거나 끄기(반대로 하기)
    S = 21; // 10101
    idx = 2;
    S ^= (1 << idx); // 10001 = 17
    cout << S << '\n';

    // 최하위 켜져 있는 비트 찾기
    S = 36; // 100100
    idx = (S & -S); // -S = 000...011011 + 1 = 000...011100 -> S & -S = 000100
    cout << idx << '\n';
    return 0;
}