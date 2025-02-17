#include<bits/stdc++.h>
using namespace std;

int n = 10, r = 3, a[10] = {1,2,3,4,5,6,7,8,9,10};

void print(const vector<int> &v){               // & 는 vector v를 직접 참조한다는 뜻.
    for(int i : v)cout << i << " ";             // main logic( O(1) ) -> print 하는 것이므로 order 1
    cout << "\n";
}
void combi(int start, vector<int> &v){
    if(v.size() == r){                          // 기저사례 (종료조건) -> 계속 push_back 하다가 원하는 사이즈에 도달하면 이를 print.
        print(v);
        return;
    }
    for(int i = start; i < n; i++){             // start 부터 시작하는 for 문, start 는 1씩 증가한다.
        v.push_back(a[i]);                      // 직접 vector 에 push_back 해서 a[i] 값을 집어넣는다.
        combi(i + 1, v);                        // Recursion
        v.pop_back();                           // print 후에 pop_back 하고 i = start + 1 이 되며 그 다음 조합이 나온다.
    }
    return;
}

int main(){
    vector<int> v;
    combi(0,v);
    return 0;
}