#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, tmp = 1;
        cin >> a >> b;
        while (b--) {
            tmp = (tmp * a) % 10;
        }
        if (tmp == 0) cout << 10 << "\n";
        else cout << tmp << "\n";
    }
}