#include<bits/stdc++.h>
using namespace std;
int N, input[1000004], NGE[1000004];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    for(int i = 0; i < N; i++){
        int j = i + 1;
        while(input[i] >= input[j] && j < N) j++;
        if(j == N) NGE[i] = -1;
        else NGE[i] = input[j];   
    }
    for(int i = 0; i < N; i++){
        cout << NGE[i] << " ";
    }
    cout << "\n";
    return 0;
}

//너무나 당연하지만 1 <= N <= 1,000,000 이고 해당 코드는 O(N^2) 이므로 시간초과가 뜰 수 밖에 없다..