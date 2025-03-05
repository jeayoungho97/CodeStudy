#include<bits/stdc++.h>
using namespace std;
int N, node, root, parent;
vector<int> tree[54];
int cnt_leaf(int here){
    int cnt = 0;
    int child = 0;
    for(int there : tree[here]){
        child++;
        cnt += cnt_leaf(there);
    }
    if(child == 0) return 1;
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> parent;
        if(parent == -1) root = i;
        else tree[parent].push_back(i);
    }
    cin >> node;
    if(node == root){
        cout << 0 << "\n";
        return 0;
    }

    // Difference with answer : This code deletes the node directly. (But not the child nodes!)
    for(vector<int> &v : tree){
        auto it = find(v.begin(), v.end(), node);
        if(it != v.end()){
            v.erase(it);
        }
    }
    cout << cnt_leaf(root) << "\n";
    return 0;
}