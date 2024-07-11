#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;
long long result = 0;

int abs(int number) {
    return number > 0 ? number : -number;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        if (i != 0 && v[i].second == v[i - 1].second) tmp = abs(v[i].first - v[i - 1].first);
        if (i != n - 1 && v[i].second == v[i + 1].second && (tmp == 0 || tmp > abs(v[i].first - v[i + 1].first))) tmp = abs(v[i].first - v[i + 1].first);
        result += tmp;
    }
    cout << result;
}