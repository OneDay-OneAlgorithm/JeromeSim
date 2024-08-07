#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        set<string> s;
        vector<string> v;
        bool result = true;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            s.insert(tmp);
            v.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            string tmp = "";
            for (int j = 0; j < v[i].size() - 1; j++) {
                tmp += v[i][j];
                if (s.find(tmp) != s.end()) result = false;
            }
        }
        if (result) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}