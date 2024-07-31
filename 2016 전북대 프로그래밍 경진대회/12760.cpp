#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int counting[101];
vector<vector<int>> v;
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            int tmp2;
            cin >> tmp2;
            tmp.push_back(tmp2);
        }
        sort(tmp.begin(), tmp.end());
        v.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int maxValue = 0;
        for (int j = 0; j < n; j++) {
            maxValue = max(v[j][i], maxValue);
        }
        for (int j = 0; j < n; j++) {
            if (v[j][i] == maxValue) counting[j]++;
        }
    }
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        maxValue = max(counting[i], maxValue);
    }
    for (int i = 0; i < n; i++) {
        if (maxValue == counting[i]) cout << i + 1 << " ";
    }
}