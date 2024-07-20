#include <iostream>
using namespace std;

int dp[16][16];

int main() {
    int N, M, K, x = -1, y = -1;
    cin >> N >> M >> K;
    if (K != 0) {
        K--;
        x = K / M;
        y = K % M;
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i < x && j > y) continue;
            if (i > x && j < y) continue;

            if (i != 0) {
                if (i - 1 == x && j == y) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                dp[i][j] += dp[i - 1][j];
            }

            if (j != 0) {
                if (i == x && j - 1 == y) {
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }

                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    cout << dp[N - 1][M - 1];
}