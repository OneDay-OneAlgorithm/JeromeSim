#include <iostream>
using namespace std;

bool adj[41][41];
int n, m, result = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    while(true) {
        int maxCnt = 0, a, b, c;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    int cnt = 0;
                    if (adj[i][j]) cnt++;
                    if (adj[i][k]) cnt++;
                    if (adj[j][k]) cnt++;

                    if (cnt == 3) continue;
                    if (cnt == 0) continue;

                    flag = false;

                    if (maxCnt < cnt) {
                        maxCnt = cnt;
                        a = i;
                        b = j;
                        c = k;
                    }
                }
            }
        }
        if (flag) break;
        adj[a][b] = true;
        adj[b][a] = true;
        adj[b][c] = true;
        adj[c][b] = true;
        adj[c][a] = true;
        adj[a][c] = true;
        result += maxCnt == 2 ? 0 : 1;

    }
    cout << result;
}