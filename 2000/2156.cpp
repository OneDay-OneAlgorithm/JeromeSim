#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int dp[10001][3];
int n, result = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    dp[0][0] = 0;
    dp[0][1] = arr[0];
    dp[0][2] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) dp[i][0] = max(dp[i - 1][j], dp[i][0]);
        for (int j = 1; j < 3; j++) dp[i][j] = dp[i - 1][j - 1] + arr[i];
    }
    for (int i = 0; i < 3; i++) result = max(result, dp[n - 1][i]);

    cout << result;
}