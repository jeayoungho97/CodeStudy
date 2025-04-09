#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 비트마스킹 -> N 개의 구역을 101101.. 과 같이 표현했을 때,
// 두 개의 선거구로 나눈 것이라 볼 수 있음.
// 각 선거구의 구역이 서로 연결되는지 확인 -> 어떻게? 연결된 구역에 같은 선거구의 구역이 하나라도 있으면 연결된 것.
// 각 선거구의 인구의 합을 서로 비교함 -> 최소값 저장

const int INF = 987654321;
int N, population[11], ret = INF;
vector<int> adj[11];

int main(){
    // input phase
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> population[i];
    }
    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        for(int j = 0; j < num; j++){
            int temp;
            cin >> temp;
            adj[i].push_back(temp);
        }
    }

    // Operating phase
    for(int i = 0; i < (1 << N); i++){
        // 선거구 구분
        int sum0 = 0, sum1 = 0;
        bool flag = false;
        vector<int> district[2];
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                // 101100 -> 1,2,5 는 0선거구  3,4,6 은 1선거구
                district[1].push_back(j + 1);
                sum1 += population[j + 1];
            }
            else {
                district[0].push_back(j + 1);
                sum0 += population[j + 1];
            }
        }

        // 각 선거구에 적어도 하나 이상 구역이 있는지 확인
        if(district[0].empty() || district[1].empty()) continue;

        // 선거구 속 구역 모두 연결되었는지 확인
        for(int j : district[0]){
            for(int k : district[0]){
                if(find(adj[j].begin(), adj[j].end(), k) != adj[j].end()) continue; // 연결되었다면 컨티뉴
                else flag = true; // 연결 안되었으면 다음 이진법으로 이동해야함
            }
        }
        for(int j : district[1]){
            for(int k : district[1]){
                if(find(adj[j].begin(), adj[j].end(), k) != adj[j].end()) continue; // 연결되었다면 컨티뉴
                else flag = true; // 연결 안되었으면 다음 이진법으로 이동해야함
            }
        }
        if(flag) continue;
        
        // 연결 모두 잘 되어있다면 각각의 구역의 인구의 차이를 뽑아냄
        ret = min(ret, abs(sum0 - sum1));

    }

    if(ret == INF){
        cout << -1 << '\n';
        return 0;
    }

    cout << ret << '\n';

    return 0;
}

// something's wrong with finding the connectivity -> change tomorrow