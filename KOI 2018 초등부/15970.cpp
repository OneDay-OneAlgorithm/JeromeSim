#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n, result;

int abs(int number) {
    return number > 0 ? number : -number;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        int tmp = 987654321;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (v[i].second == v[j].second) tmp = min(abs(v[i].first - v[j].first), tmp);
        }
        result += tmp;
    }
    cout << result;
}