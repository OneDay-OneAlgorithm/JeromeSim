#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n / 5; i++) {
            cout << "++++ ";
        }
        for (int i = 0; i < n % 5; i++) {
            cout << "|";
        }
        cout << "\n";
    }
}