#include<bits/stdc++.h>
using namespace std;

string input, result;

int main(){
    getline(cin, input);
    for(char ch : input){
        if(isupper(ch)){
            if(ch - 'A' < 13)ch += 13;  // It uses the fact that there's 26 alphabets.
            else ch -= 13;              // Therefore this code is case sensitive.
            result += ch;
        }
        else if(islower(ch)){
            if(ch - 'a' < 13)ch += 13;
            else ch -= 13;
            result += ch;
        }
        else result += ch;
    }
    cout << result << "\n";

    return 0;
}
