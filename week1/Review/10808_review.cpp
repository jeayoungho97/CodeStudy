#include<bits/stdc++.h>
using namespace std;
string input;
int result[100];
int main(){
    cin >> input;
    for(char ch : input){
        result[ch - 'a']++;
    }
    for(int i = 0; i <= 'z' - 'a'; i++){
        cout << result[i] << " ";
    }
    cout << '\n';
    return 0;
}