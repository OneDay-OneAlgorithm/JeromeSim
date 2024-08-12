#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (auto &item : v) {
        cout << item << " ";
    }
}