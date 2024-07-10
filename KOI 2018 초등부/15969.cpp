#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int maxValue = 0, minValue = 98654321;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        maxValue = max(maxValue, tmp);
        minValue = min(minValue, tmp);
    }
    cout << maxValue - minValue;
}