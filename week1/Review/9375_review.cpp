#include<bits/stdc++.h>
using namespace std;
int testcases, N;
string trash, clothes;
vector<int> result;
int main(){
    cin >> testcases;
    while(testcases--){
        int ret = 1;
        map<string, int> mp;
        cin >> N;
        while(N--){
            cin >> trash >> clothes;
            mp[clothes]++;
        }
        for(pair p : mp){
            ret *= (p.second + 1);
        }
        result.push_back(--ret);
    }
    for(int i : result) cout << i << '\n';
    return 0;
}