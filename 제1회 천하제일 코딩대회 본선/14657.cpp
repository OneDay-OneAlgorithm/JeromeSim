#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Edge {
    int node;
    int time;
};

struct Info {
    int count;
    int time;
};

struct compare {
    bool operator()(Info a, Info b) {
        if (a.count == b.count) {
            return a.time > b.time;
        }
        return a.count < b.count;
    }
};

Info myMin(Info a, Info b) {
    if (a.count == b.count) {
        if (a.time < b.time) return a;
        return b;
    }
    if (a.count > b.count) return a;
    return b;
}

vector<Edge> adj[55555];
int N, T;
bool visited[55555];
Info result{0, 987654321};

Info dfs(int here, int time) {
    priority_queue<Info, vector<Info>, compare> q;

    for (auto next : adj[here]) {
        if (visited[next.node]) continue;
        visited[next.node] = true;
        auto info = dfs(next.node, next.time);
        info.count += 1;
        info.time += next.time;
        q.push(info);
    }

    if (q.empty()) return {1, 0};

    auto first = q.top();
    q.pop();

    if (!q.empty()) {
        auto second = q.top();
        result = myMin({first.count + second.count - 1, first.time + second.time}, result);
    } else {
        result = myMin(first, result);
    }

    return first;
}

int main() {
    cin >> N >> T;
    for (int i = 0; i < N - 1; i++) {
        Edge e1, e2;
        int A, B, C;
        cin >> A >> B >> C;
        e1.node = B;
        e1.time = C;
        e2.node = A;
        e2.time = C;
        adj[A].push_back(e1);
        adj[B].push_back(e2);
    }
    visited[1] = true;
    dfs(1, 0);
    cout << (result.time + T - 1) / T;
}