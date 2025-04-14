#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool visited[1001];
std::vector<std::string> result;

void DFS(int here, std::vector<std::vector<int>>& adj){
  visited[here] = true;
  for(int there : adj[here]) {
    if(visited[there]) continue;
    DFS(there, adj);
  }
}

int main() {
  int t;
  std::cin >> t;
  while(t--) {
    bool flag = false;
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);

    int m;
    std::cin >> m;

    if (m != n - 1) flag = true;
    
    while(m--) {
      int a, b;
      std::cin >> a >> b;
      if (std::count(adj[a].begin(), adj[a].end(), b)) flag = true;

      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    if (flag) {
      result.push_back("graph");
      continue;
    }

    DFS(1, adj);

    for (int i = 1; i <= n; ++i) {
      if (!visited[n]) {
        flag = true;
        break;
      }
    }

    if (flag) result.push_back("graph");
    else result.push_back("tree");
  }

  for (std::string str : result) std::cout << str << '\n';
  return 0;
}