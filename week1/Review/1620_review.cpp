#include<bits/stdc++.h>
using namespace std;
int N, M;
string input;

map<int, string> Num_to_Pok;
map<string, int> Pok_to_Num;
vector<string> ret;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // 위 한 줄의 코드를 안 쓰면 시간초과. 또는 결과를 한 번에 묶어서 프린트하면 됨.
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> input;
        Num_to_Pok[i] = input;
        Pok_to_Num[input] = i;
    }
    for(int i = 0; i < M; i++){
        cin >> input;
        if(atoi(input.c_str())){
            // cout << Num_to_Pok[atoi(input.c_str())] <<'\n';
            ret.push_back(Num_to_Pok[atoi(input.c_str())]);
        }
        else{
            // cout << Pok_to_Num[input] << '\n';
            ret.push_back(to_string(Pok_to_Num[input]));
        }
    }
    for(string str : ret) cout << str << '\n';
    // 묶어서 프린트하는 것이 확실히 메모리와 시간을 좀 더 많이 씀.
    // 하지만 정답의 형식엔 이게 제일 맞음.
    return 0;
}