#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << min(m, k) + min(n - m, n - k);
}