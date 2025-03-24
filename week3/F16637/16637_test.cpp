#include <bits/stdc++.h>
using namespace std;

int ret = -2147483648;
int N, num[12], num_copy[12];
char calc[12], calc_copy[12];

int do_calc(int a, int* num_copy, char* calc_copy){
    if (calc_copy[a] == '+') return num_copy[a] + num_copy[a + 1];
    if (calc_copy[a] == '-') return num_copy[a] - num_copy[a + 1];
    if (calc_copy[a] == '*') return num_copy[a] * num_copy[a + 1];
    return 0;
}
int temp;
void solve(){
    copy(num, num + 12, num_copy);
    copy(calc, calc + 12, calc_copy);

    // 연산자 우선순위 없이 왼쪽에서부터 순차적으로 계산
    for (int i = 0; i < N / 2; i++) {
        num_copy[i + 1] = do_calc(i, num_copy, calc_copy);
    }

    ret = max(ret, num_copy[N/2]);
    return;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) cin >> num[i / 2];  // 숫자 입력
        else cin >> calc[(i - 1) / 2];      // 연산자 입력
    }
    solve();
    cout << ret << '\n';
    
    return 0;
}
