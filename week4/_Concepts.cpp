#include<bits/stdc++.h>
using namespace std;

const int m = 5;
string a[m] = {"apple", "strawberry", "grape", "pear", "melon"};

void go(int num){
    string ret = "";
    for(int i = 0; i < m; i++){
        if(num & (1 << i)) ret += a[i] + " ";
    }
    cout << ret << '\n';
    return;
}

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

    // 크기가 n인 집합의 모든 비트 켜기
    int n = 4;
    cout << (1 << n) - 1 << '\n';

    // idx 번째 비트 켜기
    S = 18; // 10010
    idx = 3;
    S |= (1 << idx);
    cout << S << '\n';

    // idx 번째 비트가 켜져 있는지 확인하기
    S = 18; // 10010
    idx = 1;
    if(S & (1 << idx)){
        cout << "idx : " << idx << " is turned on.\n";
    } else {
        cout << "idx : " << idx << " is not turned on.\n";
    }

    // 비트마스킹 -> 경우의 수
    for(int i = 0; i < (1 << m); i++){
        string ret = "";
        for(int j = 0; j < m; j++){
            if(i & (1 << j)){
                ret += (a[j] + " ");
            }
        }
        cout << ret << '\n';
    }

    //  비트마스킹 -> 매개변수 전달
    for(int i = 1; i < m; i++){
        go(1 | (1 << i));
    }
    return 0;
}