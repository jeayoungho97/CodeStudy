#include<bits/stdc++.h>
using namespace std;

vector<int> ascii;                  // change the input string into ascii code and put it in a vector
string input;
int result;                         // globally declared, so initially 0

int main(){
    cin >> input;

    for(char c : input){
        ascii.push_back(int(c));
    }

    for(int i = 97; i < 123; i++){
        for(int j : ascii){
            if (j == i)result += 1;
        }
        cout << result << " ";      // print for each alphabet
    }
}

//ASCII 97 ~ 122