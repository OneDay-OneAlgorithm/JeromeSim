#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    set<int> s;
    int arr[2222];
    int result = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] == 0 && arr[j] != arr[j + 1]) continue;
            if (arr[j] == 0 && arr[i] != arr[i + 1]) continue;
            if (arr[i] == 0 && arr[j] == 0 && (arr[j + 1] != 0 || j + 1 >= N)) continue;

            int tmp = arr[i] + arr[j];
            if (s.find(tmp) != s.end()) continue;
            int lowerIndex = lower_bound(arr, arr + N, tmp) - arr;
            int upperIndex = upper_bound(arr, arr + N, tmp) - arr;
            result += upperIndex - lowerIndex;

            s.insert(tmp);
        }
    }
    cout << result;
    return 0;
}
