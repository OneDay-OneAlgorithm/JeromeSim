#include <iostream>
using namespace std;

int main() {
    int N, T, P, result = 0;
    int sizes[6];
    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> sizes[i];
    }
    cin >> T >> P;
    for (auto &size : sizes) {
        result += (size + T - 1) / T;
    }
    cout << result << "\n" << N / P << " " << N % P;
}