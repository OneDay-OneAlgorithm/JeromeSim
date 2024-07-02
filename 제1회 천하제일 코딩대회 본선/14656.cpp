#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp != i) res++;
    }
    cout << res;
}