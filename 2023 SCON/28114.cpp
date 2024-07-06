#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct P {
    int num;
    int year;
    string last;
};

bool cmp2(P a, P b) {
    return a.num > b.num;
}

bool cmp1(P a, P b) {
    return a.year < b.year;
}

int main() {
    P p[3];
    for (int i = 0; i < 3; i++) cin >> p[i].num >> p[i].year >> p[i].last;
    sort(p, p + 3, cmp1);
    for (int i = 0; i < 3; i++) cout << p[i].year % 100;
    cout << "\n";
    sort(p, p + 3, cmp2);
    for (int i = 0; i < 3; i++) cout << p[i].last[0];
}