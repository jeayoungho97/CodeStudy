#include<bits/stdc++.h>
using namespace std;

int ret = -2147483648;
int N, num[12], num_copy[12];
char calc[12], calc_copy[12];
// num 과 calc 는 각각 input 의 값을 직접 입력받으나, 짝수번째 입력은 num 으로,홀수번째 입력은 calc 에 저장되고 index 는 num[0], num[1], num[2] 와 같은 식으로 저장됨.
vector<int> par;
// par(enthesis) 는 위치(int)의 벡터의 형태이며, par = {0, 3} 이라면 0번째 숫자와 3번째 숫자 앞에 괄호가 있다는 뜻. 괄호를 닫는것은 자동으로 결정되므로 여는 곳의 위치만 담으면 됨.
// 다만 괄호가 성립이 안되는 경우가 있으므로 그것은 함수에서 예외처리함.


int do_calc(int a, int* num_copy, char* calc_copy){
    if(calc_copy[a] == '+') return num_copy[a] + num_copy[a+1];
    if(calc_copy[a] == '-') return num_copy[a] - num_copy[a+1];
    if(calc_copy[a] == '*') return num_copy[a] * num_copy[a+1];
    return 0;
}

void solve(){
    // 원래 입력받은 배열을 해치지 않기 위해 복제. 연산자도 복제.
    copy(num, num + 12, num_copy);
    copy(calc, calc + 12, calc_copy);

    // 괄호가 있을 경우 연산을 수행 -> 예를 들어 8 + ( 7 * 3 ) 이라면 7 * 3 을 수행한 후 식을 8 + 21 + 0  으로 바꿔줌.
    if(par.size()){
        for(int i = 1; i < par.size(); i++){
            // 괄호가 성립이 안되는 것 예외처리. -> 예를 들어 par = {0,1,4} 라면 0번째 숫자와 1번째 숫자 앞에 괄호가 있다는 것인데, 0번째에 괄호가 있다면 자동으로 1번째 숫자 뒤에는 괄호가 닫혀야하므로 불가능함.
            if(par[i] - par[i - 1] == 1) return;
        }
        for(int i = 0; i < par.size(); i++){
            num_copy[par[i]] = do_calc(par[i], num_copy, calc_copy);
            // 계산결과 + 0 으로 바꿔줌 -> 다만 복제된 배열의 값을 바꿔주는 것이므로 원본은 그대로임 -> 그래야 괄호를 칠 수 있는 모든 경우에 대해 계산 가능
            calc_copy[par[i]] = '+';
            num_copy[par[i] + 1] = 0;
        }
    }
    // 괄호의 계산을 모두 처리한 이후 식을 계산
    for(int i = 0; i < N / 2; i++){
        num_copy[i + 1] = do_calc(i, num_copy, calc_copy);
    }

    //최대치를 뽑아냄
    ret = max(ret, num_copy[N / 2]);
}

// 괄호를 추가하는 recursive function -> 이걸 생각하는게 좀 어려웠음.
void add_par(int cnt){
    if(cnt == N / 2){
        solve();
        return;
    }
    add_par(cnt + 1);
    par.push_back(cnt);
    add_par(cnt + 1);
    par.pop_back();
    return;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) cin >> num[i / 2];
        else cin >> calc[(i - 1) / 2];
    }
    
    add_par(0);
    cout << ret << '\n';
    
    return 0;
}