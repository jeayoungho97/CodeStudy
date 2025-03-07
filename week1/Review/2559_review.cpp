#include<bits/stdc++.h>
using namespace std;
int N, K, psum[100004];
int ret = -10000004;
int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        int temp;
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    for(int i = 0; i <= N - K; i++){
        ret = max(ret, psum[i + K] - psum[i]);
    }
    // 수열의 합 등 합할 때에는 범위를 좀 더 꼼꼼히 따지자.
    cout << ret << '\n';
    return 0;
}