#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N, mp, mf, ms, mv, min_cost = INF;
vector<int> min_ing;
struct nutrition{
    int p, f, s, v, c;
    // 구조체 생성자를 이용해서 각 요소 디폴트값 0
    nutrition() : p(0), f(0), s(0), v(0), c(0) {}
};

void cmp_ing(vector<int> ing){
    int min_size = min_ing.size();
    int ing_size = ing.size();
    int size = min(min_size, ing_size);
    for(int i = 0; i < size; i++){
        if(ing[i] < min_ing[i]) {
            min_ing = ing;
            return;
        }
        else if(ing[i] > min_ing[i]) return;
        else continue;
    }
    return;
}

int main(){
    // 데이터 입력받음
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    nutrition a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
    }

    // 각 재료를 넣을지 말지 경우의 수 생성
    for(int i = 0; i < (1 << N); i++){
        nutrition ret;
        vector<int> ing;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                ret.p += a[j].p;
                ret.f += a[j].f;
                ret.s += a[j].s;
                ret.v += a[j].v;
                ret.c += a[j].c;
                ing.push_back(j + 1);
            }
        }
        if(ret.p < mp || ret.f < mf || ret.s < ms || ret.v < mv) continue;
        if(min_ing.empty() && ret.c < min_cost) min_ing = ing;

        if(ret.c < min_cost){
            min_cost = ret.c;
            min_ing = ing;
        }
        else if(ret.c == min_cost){
            cmp_ing(ing);
        }
    }
    if(min_cost == INF) cout << -1 << '\n';
    else {
        cout << min_cost << '\n';
        for(int i : min_ing) cout << i << " ";
        cout << '\n';
    }
    return 0;
}