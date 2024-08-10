#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[500001];
bool visited[500001];
int count = 0;

void dfs(int here) {
    bool flag = true;

    for (int i = 0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if (visited[next]) continue;
        visited[next] = true;
        dfs(next);
        flag = false;
    }

    if (flag) count++;
}

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[1] = true;
    dfs(1);
    cout << fixed;
    cout.precision(10);
    cout << w / (double)count;
}