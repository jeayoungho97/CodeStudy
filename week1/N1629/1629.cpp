#include <bits/stdc++.h>
using namespace std;

int A, B, C, rep;
long long ret;
vector<long long> rem;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> A >> B >> C;
    ret = A % C;
    for(int i = 0; i < B-1 ; i++){
        if(find(rem.begin(),rem.end(),ret) != rem.end()){
            int idx = B % rem.size() - 1;
            if(idx == -1)idx = rem.size() - 1;
            ret = rem[idx];
            break;
        }
        rem.push_back(ret);
        ret = ret * A % C;
    }
    cout << ret << "\n";
    return 0;
}

// 나머지 정리?
// Hmm.... Very Hard