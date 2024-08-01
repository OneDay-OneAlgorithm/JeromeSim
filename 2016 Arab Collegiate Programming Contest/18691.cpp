#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int G, C, E;
        cin >> G >> C >> E;
        if (C >= E) cout << 0 << "\n";
        else {
            cout << (E - C) * (2 * (G - 1) + 1) << "\n";
        }
    }
}