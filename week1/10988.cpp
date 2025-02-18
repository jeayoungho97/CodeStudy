#include<bits/stdc++.h>
using namespace std;
string input;
int main(){
    cin >> input;
    int n = input.length();
    for(int i = 0; i < n/2; i++){
        if(input[i] == input[n-1-i])continue;
        else{
            cout << 0 << "\n";
            exit(0);
        }
    }
    cout << 1 << "\n";
    return 0;
}