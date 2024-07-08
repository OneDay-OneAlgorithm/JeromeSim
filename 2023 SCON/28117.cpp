#include <iostream>
#include <string>
using namespace std;

int calc(int n) {
    int dp[100];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n, seqCount = 0, result = 1;
    string str;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'l' && str[i + 1] == 'o' && str[i + 2] == 'n' && str[i + 3] == 'g') {
            seqCount += 1;
            i += 3;
        }
        else {
            result *= calc(seqCount);
            seqCount = 0;
        }
    }
    result *= calc(seqCount);

    cout << result;
}