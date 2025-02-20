#include<bits/stdc++.h>
using namespace std;
map<string,int> input;
int gears[32], cases, n;
int main(){
    cin >> n;
    for(int j = 0; j < n; j++){
        string trash, gear;
        cin >> trash >> gear;
        if(input[gear])input[gear]++;
        else input[gear]=1;
    }
    for(auto pair : input){
        cout << pair.second << " ";
    }
    cout << "\n";
    return 0;
}