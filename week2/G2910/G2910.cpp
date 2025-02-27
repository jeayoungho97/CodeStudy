#include<bits/stdc++.h>
using namespace std;

int N, C, temp;
map<int, int> input, input_order;
//input.first -> number, input_second -> frequency
//input_order.first -> number, input_order.second -> order (smaller is first)
vector<pair<int,int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return input_order[a.second] < input_order[b.second];
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> temp; input[temp]++;
        if(input_order[temp] == 0)input_order[temp] = i + 1;
        // input_order[temp] = i 와 input_order[temp] = i + 1 은 큰 차이가 있음.
        // i == 0 일 때 input_order[temp] = 0 이 되는데, 
        // 이는 아직 등장하지 않았다는 의미가 되므로 i + 1 로 저장을 해야 첫 번째 숫자도 순서가 제대로 저장이 됨.
    }
    for(auto i : input){
        v.push_back({i.second, i.first});
    }
    sort(v.begin(), v.end(), compare);

    for(auto i : v){
        for(int j = 0; j < i.first; j++){
            cout << i.second << " ";
        }
    }
    cout << "\n";
    return 0;
}