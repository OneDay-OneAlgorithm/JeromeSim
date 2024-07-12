#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    char result;
    switch (sum % 4) {
        case 0: result = 'N'; break;
        case 1: result = 'E'; break;
        case 2: result = 'S'; break;
        case 3: result = 'W'; break;
    }
    cout << result;
}