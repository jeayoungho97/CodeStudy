#include<bits/stdc++.h>
using namespace std;

int N, M, input, ret = 1e9;
vector<pair<int,int>> chicken, house, v;

int solve(vector<pair<int,int>> &v){
    int distance_sum = 0;
    for(pair<int,int> p : house){
        int distance = 2 * (N - 1);
        for(int i = 0; i < M; i++){
            distance = min(abs(p.first - v[i].first) + abs(p.second - v[i].second), distance);
        }
        distance_sum += distance;
    }
    return distance_sum;
}

void combi(int start, vector<pair<int,int>> &v){
    if(v.size() == M) 
    {
        ret = min(ret,solve(v));
        return;
    }
    for(int i = start; i < chicken.size(); i++){
        v.push_back(chicken[i]);
        combi(i + 1, v);
        v.pop_back();
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            if(input == 1) house.push_back({i,j});
            if(input == 2) chicken.push_back({i,j});
        }
    }
    combi(0,v);
    cout << ret << '\n';
    return 0;
}