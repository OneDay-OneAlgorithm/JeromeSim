#include <iostream>
using namespace std;

int arr[500001];

int main() {
    int n, diff;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (i == 0) continue;
        if (i == 1) diff = arr[i] - arr[i - 1];
        else {
            if (diff != arr[i] - arr[i - 1]) {
                flag = true;
                break;
            }
        }
    }
    if (flag == false) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; i++) cout << 0 << " ";
    } else {
        cout << "NO";
    }
}