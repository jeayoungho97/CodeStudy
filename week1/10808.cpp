#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> ascii;
    string input;
    cin >> input;
    for(char c : input){
        ascii.push_back(int(c));
    }

    sort(ascii.begin(),ascii.end());

    for(int i = 97; i < 123; i++){
        int result = 0;
        for(int j : ascii){
            if (j == i)result += 1;
        }
        cout << result << " ";
    }
}

//ASCII 97 ~ 122