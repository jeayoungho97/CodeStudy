#include<bits/stdc++.h>
using namespace std;

int N, K, temp;
int psum[100001], result = -1000000;

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    for(int j = K; j <= N; j++){
        result = max(result, psum[j] - psum[j-K]);
    }
    cout << result << "\n";
    return 0;
}

// Prefix Sum 은 미리 N개를 더해놓고 N-K 번 빼면 됨 O(2N-K)
// Psum이 훨씬 코드도 간단하고 시간복잡도에서도 유리함.