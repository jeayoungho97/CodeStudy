#include<bits/stdc++.h>
using namespace std;
int N, C, temp;
struct Info{
    int freq = 0;
    int first = 0;
};
map<int, Info> input;
vector<int> ret;
bool cmp(int i, int j){
    if(input[i].freq == input[j].freq) return input[i].first < input[j].first;
    return input[i].freq > input[j].freq;
}
int main(){
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> temp; input[temp].freq++;
        if(input[temp].first == 0) input[temp].first = i + 1;
    }
    
    for(auto i : input){
        ret.push_back(i.first);
    }
    sort(ret.begin(), ret.end(), cmp);
    for(auto i : ret){
        for(int j = 0; j < input[i].freq; j++){
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}