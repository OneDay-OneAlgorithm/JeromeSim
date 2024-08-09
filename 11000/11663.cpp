#include <iostream>
#include <algorithm>
using namespace std;

int points[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> points[i];
    sort(points, points + n);
    while (m--) {
        int start, end, result;
        cin >> start >> end;
        int startIndex = lower_bound(points, points + n, start) - points;
        int endIndex = lower_bound(points, points + n, end) - points;
        result = endIndex - startIndex - 1;
        if (points[startIndex] >= start) result++;
        if (points[endIndex] == end) result++;

        if (startIndex == n) {
            cout << 0 << "\n";
        } else {
            cout << result << "\n";
        }
    }
}