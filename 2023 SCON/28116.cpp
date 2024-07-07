#include <iostream>
using namespace std;

int arr[500001];
int index[500001];
int result[500001];

int abs(int num) {
    return num > 0 ? num : -num;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        index[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int nowIndex = index[i];
        int swapIndex = i - 1;
        int diff = abs(nowIndex - swapIndex);
        result[arr[nowIndex]] += diff;
        result[arr[swapIndex]] += diff;
        int tmp = arr[swapIndex];
        arr[swapIndex] = arr[nowIndex];
        arr[nowIndex] = tmp;

        tmp = index[arr[swapIndex]];
        index[arr[swapIndex]] = index[arr[nowIndex]];
        index[arr[nowIndex]] = tmp;
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}