#include <bits/stdc++.h>
using namespace std;
int N, Delete_node, parent, root;
vector<int> adj[54];
int dfs(int here){
    int result = 0;
    int child = 0;
    for(int there : adj[here]){
        if(there == Delete_node) continue;              // If the child is the node to be deleted, continue. (Cool)
        child++;
        result += dfs(there);
    } 
    if(child == 0) return 1;                            // child counts only when there "is" a child node. So if child == 0, it's the leaf node.
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int node = 0; node < N; node++){
        cin >> parent;
        if(parent == -1) root = node;
        else adj[parent].push_back(node);               // Elements of adj[parent] are the child nodes.
    }
    cin >> Delete_node;
    if(Delete_node == root){
        cout << 0 << "\n";
        return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}