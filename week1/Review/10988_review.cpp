#include<bits/stdc++.h>
using namespace std;
string input;
int main(){
    cin >> input;
    string temp = input;
    reverse(temp.begin(), temp.end());
    if(temp == input) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}