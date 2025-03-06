#include<bits/stdc++.h>
using namespace std;
int N, a[1000004], result[1000004];
stack<int> stk;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> N;
    memset(result, -1, sizeof(result));
    for(int i = 0; i < N; i++){
        cin >> a[i];
        while(stk.size() && a[stk.top()] < a[i]){
            result[stk.top()] = a[i]; stk.pop();
        }
        stk.push(i);
    }
    for(int i = 0; i < N; i++) cout << result[i] << " ";
    cout << "\n";
    return 0;
} 