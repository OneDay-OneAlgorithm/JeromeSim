#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int whoWin(int a, int b, int beforeWin) {
    if (a == b) return -beforeWin;
    if (a == 1 && b == 3) return 1;
    if (b == 1 && a == 3) return -1;
    return a - b;
}

int main() {
    int n, beforeWin = 0, seq = 1, maxSeq = 1;
    vector<int> arr[2];
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            arr[i].push_back(tmp);
        }
    }
    for (int i = 0; i < n; i++) {
        int winner = whoWin(arr[0][i], arr[1][i], beforeWin);
        if (winner == beforeWin) {
            seq++;
            maxSeq = max(seq, maxSeq);
        }
        else seq = 1;
        beforeWin = winner;
    }
    cout << maxSeq;
}