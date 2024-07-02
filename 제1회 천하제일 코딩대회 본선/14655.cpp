#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int tmp;
        cin >> tmp;
        sum += abs(tmp);
    }
    cout << sum;
}