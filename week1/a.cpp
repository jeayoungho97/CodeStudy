#include<bits/stdc++.h>
using namespace std;

string input;

int main(){
    cin >> input;
    int n = input.length();
    for(int i = 0; i < n/2; i++){
        if(input[i] == input[n-1-i])cout << "input[" << i << "] is okay.";
        else cout << "input[" << i << "] is not okay.";
    }
    return 0;
}