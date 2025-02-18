#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> ascii;
    string input;
    cin >> input;
    for(char c : input){
        ascii.push_back(int(c));
    }

    sort(ascii.begin(),ascii.end());    // ASCII 크기 순으로 분류가 필요할까?

    for(int i = 97; i < 123; i++){
        int result = 0;
        for(int j : ascii){
            if (j == i)result += 1;
        }
        cout << result << " ";
    }
}

//ASCII 97 ~ 122