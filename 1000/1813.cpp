#include <iostream>
using namespace std;

int count[51];
int result = -1;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        count[tmp]++;
    }
    for  (int i = 0; i <= n; i++) {
        if (count[i] == i) result = i;
    }
    cout << result;
}