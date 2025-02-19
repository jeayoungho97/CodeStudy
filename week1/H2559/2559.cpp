#include<bits/stdc++.h>
using namespace std;

int N, K;
int sum;

int main(){
    cin >> N >> K;
    int input[N];
    for(int i =0; i < N; i++){
        cin >> input[i];
    }

    // set initial value of sum
    for(int j = 0; j < K; j++){
        sum += input[j];
    }
    for(int k = 0; k <= N - K; k++){
        int temp = 0;
        for(int m = k; m < k + K; m++){
            temp += input[m];           // N-K번을 K개씩 더하는거라 O((N-K)*K)
        }
        sum = max(sum, temp);
    }
    cout << sum << "\n";
    
    return 0;
}

