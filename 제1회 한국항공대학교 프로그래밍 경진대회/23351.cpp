#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, A, B, result = 0;
    vector<int> leaves;
    cin >> N >> K >> A >> B;
    for (int i = 0; i < N; i++) leaves.push_back(K);

    while (true) {
        result++;
        int minValue = 987654321;
        int minIndex = 0;
        for (int i = 0; i < leaves.size() - A + 1; i++) {
            int sum = 0;
            for (int j = i; j < i + A; j++) sum += leaves[j];
            if (sum < minValue) {
                minIndex = i;
                minValue = sum;
            }
        }
        for (int i = minIndex; i < minIndex + A; i++) leaves[i] += B;
        bool flag = false;
        for (int i = 0; i < leaves.size(); i++) {
            leaves[i]--;
            if (leaves[i] <= 0) flag = true;
        }
        if (flag) break;
    }

    cout << result;
}