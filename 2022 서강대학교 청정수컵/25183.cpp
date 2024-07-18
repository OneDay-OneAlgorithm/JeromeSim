#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str;
    bool result = false;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (i + 4 >= str.size()) continue;

        for (int j = i; j < i + 5; j++) {
            if (j == i + 4) result = true;
            if (str[j] - str[j + 1] != 1 && str[j + 1] - str[j] != 1) break;
        }
    }

    if (result) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}