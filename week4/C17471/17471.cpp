#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

// 비트마스킹 -> N 개의 구역을 101101.. 과 같이 표현했을 때,
// 두 개의 선거구로 나눈 것이라 볼 수 있음.
// 각 선거구의 구역이 서로 연결되는지 확인 -> 어떻게? 연결된 구역에 같은 선거구의 구역이 하나라도 있으면 연결된 것.
// 각 선거구의 인구의 합을 서로 비교함 -> 최소값 저장

const int INF = 987654321;
const int MAX_N = 11;

int N, population[MAX_N], ret = INF;
vector<int> adj[MAX_N];

// BFS 를 이용해 각 선거구의 구역이 연결되었는지 확인
bool is_connected(const vector<int>& district){
    unordered_set<int> district_set(district.begin(), district.end());
    vector<bool> visited(N + 1, false);
    queue<int> q;

    // 선거구의 첫번째 구역에서 시작해 퍼져나감
    q.push(district[0]);
    visited[district[0]] = true;
    int cnt = 1;

    while(!q.empty()){
        int here = q.front(); q.pop();
        for(int there : adj[here]){
            if(!visited[there] && district_set.count(there)){
                visited[there] = true;
                q.push(there);
                cnt++;
            }
        }
    }

    // 만일 cnt 와 district 의 크기가 다르다면 모든 구역이 다 연결되지 않았다는 뜻
    return cnt == district.size();
}

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
        // 선거구가 하나밖에 없는 경우 거름.
        if(i == 0 || i == (1 << N) - 1) continue;

        // 선거구 구분
        int sum0 = 0, sum1 = 0;
        vector<int> district0, district1;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                // ex. 101100 -> 1,2,5 는 0선거구  3,4,6 은 1선거구
                district1.push_back(j + 1);
                sum1 += population[j + 1];
            }
            else {
                district0.push_back(j + 1);
                sum0 += population[j + 1];
            }
        }

        // 선거구 속 구역 모두 연결되었는지 확인
        if(is_connected(district0) && is_connected(district1)){
            // 연결 모두 잘 되어있다면 각각의 구역의 인구의 차이를 뽑아냄
            ret = min(ret, abs(sum0 - sum1));
        }
    }

    // ret == INF 인 상태로 계속 있다면 모든 경우에서 두 개의 선거구로 나뉘어진 적이 없다는 뜻이므로 -1 제출
    if(ret == INF){
        cout << -1 << '\n';
        return 0;
    }

    cout << ret << '\n';

    return 0;
}