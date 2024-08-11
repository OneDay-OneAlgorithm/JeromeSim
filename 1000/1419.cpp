#include <iostream>
using namespace std;

int main() {
    int l, r, k, result = 0;
    cin >> l >> r >> k;
    if (k == 2) {
        if (r < 2) {
            cout << 0;
        } else {
            if (l < 3) l = 3;
            result = r - l + 1;
            cout << result;
        }
    } else if (k == 3) {
        if (r < 6) {
            cout << 0;
        } else {
            if (l < 6) l = 6;
            while(l % 3 != 0) l++;
            while(r % 3 != 0) r--;
            result = (r - l) / 3 + 1;
            cout << result;
        }
    } else if (k == 4) {
        if (r < 14) {
            if (l <= 10 && r >= 10) result++;
            cout << result;
        } else {
            if (l <= 10) result++;
            if (l < 14) l = 14;
            while(l % 2 != 0) l++;
            while(r % 2 != 0) r--;
            result += (r - l) / 2 + 1;
            cout << result;
        }
    } else {
        if (r < 15) {
            cout << 0;
        } else {
            if (l < 15) l = 15;
            while(l % 5 != 0) l++;
            while(r % 5 != 0) r--;
            result += (r - l) / 5 + 1;
            cout << result;
        }
    }
}