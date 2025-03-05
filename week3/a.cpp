#include<bits/stdc++.h>
using namespace std;
int n, cnt;
const int INF = 1e7;
int main(){
    cin >> n;
    for(int i = 2400; i <INF; i++){
        string a = to_string(i);
        if(a.find("2400") != string::npos){
            cnt++;
            if(n == cnt){
                cout << a << '\n';
                break;
            }
        }
    }   
    return 0;
}