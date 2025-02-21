#include<bits/stdc++.h>
using namespace std;

int n, m, cnt, input[15001];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> input[i];
    if(m > 200000)cout << 0 << "\n";
    else{
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(input[i] + input[j] == m)cnt++;
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}