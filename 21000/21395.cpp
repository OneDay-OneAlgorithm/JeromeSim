#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[100001];
vector<int> primes;

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    for (int i = 2; i <= 100000; i++) {
        if (check[i]) continue;
        primes.push_back(i);
        for (int j = 2 * i; j <= 100000; j += i) check[j] = true;
    }

    int T;
    cin >> T;
    while (T--) {
        vector<int> x;
        int n, result = 987654321;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            x.push_back(tmp);
        }
        sort(x.begin(), x.end());
        for (int i = 0; i < primes.size() - x.size() + 1; i++) {
            int sum = 0;
            for (int j = 0; j < x.size(); j++) {
                sum += abs(x[j] - primes[i + j]);
            }
            result = min(result, sum);
        }
        cout << result << "\n";
    }
}