#include<bits/stdc++.h>
using namespace std;
int N, M;
map<int,string> pokemon1;   // map is designed for fast retrieval by key, not value!
map<string,int> pokemon2;   // Since we need a method to call a pokemon by number and vice versa,we make two maps. 
string result[100001];      // Making two maps is an idea I stole from the answer code.
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){    // i starts from 1, because the index of calling pokemon starts from 1.
        string temp;
        cin >> temp;
        pokemon1.insert({i, temp});
        pokemon2.insert({temp, i});
    }
    for(int i = 0; i < M; i++){
        string temp;
        cin >> temp;
        if(isdigit(temp[0])){
            result[i] = pokemon1[stoi(temp)];
        }
        else{
            result[i] = to_string(pokemon2[temp]);  // to input integer into array of string, we need to_string function
        }
    }
    for(int i = 0; i < M; i++){
        cout << result[i] << "\n";
    }
    return 0;
}