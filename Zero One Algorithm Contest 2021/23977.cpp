#include <iostream>
using namespace std;

long long K, N, result;
long long A[8];
long long lcm;

long long gcd(long long a, long long b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    cin >> K >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    lcm = A[0];
    for (int i = 1; i < N; i++) {
        lcm = lcm * A[i] / gcd(lcm, A[i]);
    }
    cout << lcm - K;
}
