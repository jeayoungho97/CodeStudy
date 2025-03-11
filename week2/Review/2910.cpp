#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, C, temp;
map<int, int> Data;
map<int, int> order;
vector<pair<int,int>> result;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return order[a.first]<order[b.first];
    return a.second > b.second;
}

int main(){
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> temp;
        Data[temp]++;
        if(order[temp] == 0) order[temp] = i + 1;
    }
    for(auto i : Data) result.push_back(i);
    sort(result.begin(), result.end(), compare);
    for(pair p : result){
        for(int i = 0; i < p.second; i++){
            cout << p.first << " ";
        }
    }
cout << '\n';
    return 0;
}