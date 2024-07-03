#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 987654321

vector<pair<int,int>> v;
int n, m, l, k, result = MAX;

int counting(int x, int y) {
    int count = v.size();
    for (auto & coord : v) {
        if (x - 1 <= coord.first && y - 1 <= coord.second && x + l >= coord.first && y + l >= coord.second) {
            count--;
        }
    }
    return count;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    cin >> n >> m >> l >> k;
    for (int i = 0; i < k; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (abs(v[i].first - v[j].first) > l + 1) continue;
            if (abs(v[i].second - v[j].second) > l + 1) continue;
            int x, y;

            if (v[i].first == v[j].first) {
                pair<int, int> a = v[i].second < v[j].second ? v[i] : v[j];
                pair<int, int> b = v[i].second < v[j].second ? v[j] : v[i];

                x = a.first + 1;
                y = a.second + 1;
                result = min(result, counting(x, y));

                x -= (l + 1);
                result = min(result, counting(x, y));

                x = b.first + 1;
                y = b.second - l;
                result = min(result, counting(x, y));

                x -= (l + 1);
                result = min(result, counting(x, y));
            } else if (v[i].second == v[j].second) {
                pair<int, int> a = v[i].first < v[j].first ? v[i] : v[j];
                pair<int, int> b = v[i].first < v[j].first ? v[j] : v[i];

                x = a.first + 1;
                y = a.second + 1;
                result = min(result, counting(x, y));

                y -= (l + 1);
                result = min(result, counting(x, y));

                x = b.first - l;
                y = b.second + 1;
                result = min(result, counting(x, y));

                y -= (l + 1);
                result = min(result, counting(x, y));
            } else {
                pair<int, int> a = v[i].second < v[j].second ? v[i] : v[j];
                pair<int, int> b = v[i].second < v[j].second ? v[j] : v[i];

                if (a.first < b.first) {
                    x = a.first + 1;
                    y = b.second - l;
                    result = min(result, counting(x, y));

                    x = b.first - l;
                    y = a.second + 1;
                    result = min(result, counting(x, y));
                } else {
                    x = a.first - l;
                    y = b.second - l;
                    result = min(result, counting(x, y));

                    x = b.first + 1;
                    y = a.second + 1;
                    result = min(result, counting(x, y));
                }
            }
        }
    }

    if (result == MAX) cout << v.size() - 1;
    else cout << result;
}