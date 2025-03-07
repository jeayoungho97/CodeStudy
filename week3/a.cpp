#include<bits/stdc++.h>
using namespace std;

const int n = 3;
int a[3][3] = {
    {10, 20, 21},
    {70, 90, 12},
    {80, 110, 120}
};
int sum, result, visited[3][3];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
vector<int> v;
vector<vector<int>> results;
void print(){
    for(int i : v) cout << i << " ";
    cout << '\n';
}

void go(int y, int x){
    if(y == n-1 && x == n-1){
        print();
        for(int i : v) sum += i;
        cout << sum << '\n';
        if(sum > result){
            result = sum;
            results.clear();
            results.push_back(v);
        }
        else if(sum == result){
            results.push_back(v);
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        v.push_back(a[ny][nx]);
        go(ny, nx);
        visited[ny][nx] = 0;
        v.pop_back();
    }
}

int main(){
    visited[0][0] = 1;
    v.push_back(a[0][0]);
    go(0,0);
    cout << "Most money earned : " << result << '\n';
    cout << "And the route(s) is(are) : \n";
    for(vector<int> v : results){
        for(int i : v) cout << i << " ";
        cout << '\n';
    } 
    return 0;
}