#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, k, q;
    set<char> s;
    vector<pair<int, char>> v;

    s.insert('A');

    cin >> n >> k >> q;
    for (int i = 1; i <= k; i++) {
        int r;
        char p;
        cin >> r >> p;
        v.emplace_back(r, p);
    }

    if (v[q - 1].first == 0) {
        cout << "-1";
        return 0;
    }

    for (int i = 1; i <= k; i++) {
        int r = v[i - 1].first;
        char p = v[i - 1].second;

        if (q <= i) s.insert(p);
        if (v[q - 1].first == r) s.insert(p);
    }

    for (int i = 0; i < n; i++) {
        char ch = 'A' + i;
        if (s.find(ch) == s.end()) cout << ch << " ";
    }
}