#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string strs[101];
    int T;
    long long seq[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> strs[i];
    }
    for (int i = 0; i < T; i++) {
        long long result = 0;
        int pos = 0;
        map<char, long long> m;
        string str = strs[i];
        for (int j = 0; j < str.size(); j++) {
            if (m.find(str[j]) != m.end()) continue;
            m[str[j]] = seq[pos];
            pos++;
        }
        if (pos == 1) pos++;
        long long factor = 1;
        for (int j = str.size() - 1; j >= 0; j--) {
            result += factor * m[str[j]];
            factor *= pos;
        }
        cout << "Case #"  << i + 1 << ": " << result << "\n";
    }
}