#include <iostream>
using namespace std;

char map[666][666];
int n, m, k, result = 0;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int pi = 0; pi < k; pi++) {
        for (int pj = 0; pj < k; pj++) {
            int check[66];
            char maxChar = 'A';
            for (int i = 0; i < 66; i++) check[i] = -1;
            for (int i = pi; i < n; i += k) {
                for (int j = pj; j < m; j += k) {
                    if (check[map[i][j] - 'A'] == -1) check[map[i][j] - 'A'] = 1;
                    else check[map[i][j] - 'A']++;
                }
            }
            for (int i = 0; i < 66; i++) {
                if (check[maxChar - 'A'] < check[i]) maxChar = i + 'A';
            }
            result += (n / k) * (m / k) - check[maxChar - 'A'];
            for (int i = pi; i < n; i += k) {
                for (int j = pj; j < m; j += k) {
                    map[i][j] = maxChar;
                }
            }
        }
    }
    cout << result << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}