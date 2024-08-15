#include <iostream>
using namespace std;
#define MAX 1000000

int dp[MAX + 1];
int prevs[MAX + 1];

int main() {
    dp[1] = 0;
    prevs[1] = 0;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        if (i * 3 <= MAX && (dp[i * 3] == 0 || dp[i * 3] >= dp[i] + 1)) {
            prevs[i * 3] = i;
            dp[i * 3] = dp[i] + 1;
        }
        if (i * 2 <= MAX && (dp[i * 2] == 0 || dp[i * 2] >= dp[i] + 1)) {
            prevs[i * 2] = i;
            dp[i * 2] = dp[i] + 1;
        }
        if (i + 1 <= MAX && (dp[i + 1] == 0 || dp[i + 1] >= dp[i] + 1)) {
            prevs[i + 1] = i;
            dp[i + 1] = dp[i] + 1;
        }
    }
    cout << dp[n] << "\n";
    int tmp = n;
    while (tmp != 0) {
        cout << tmp << " ";
        tmp = prevs[tmp];
    }
}