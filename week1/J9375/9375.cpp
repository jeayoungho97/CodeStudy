#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cases, clothes;
int main(){
    cin >> cases;
    ll result[cases];                       // Make a result for each cases and print at once.
    for(int i = 0; i < cases; i++){
        map<string,int> input;              // Make a map for each case. 
        result[i] = 1;
        cin >> clothes;
        for(int j = 0; j < clothes; j++){
            string a, b;                    // we can ignore a.
            cin >> a >> b;
            input[b]++;                     // The integer value for map is initially 0.
        }
        for(auto pair : input){             // We use auto to automatically get the values of map.
            result[i] *= pair.second + 1;
        }
        result[i]--;                        // MAIN LOGIC : Say we have 3 hats, 2 pants, 5 glasses. Then we have (3+1)*(2+1)*(5+1)-1 number of cases. = 3 + 2 + 5 + 3*2 + 3*5 + 2*5 + 3*2*5 -> Binomial Distribution.
    }
    for(int i : result) cout << i << "\n";
    return 0;
}