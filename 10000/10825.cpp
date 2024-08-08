#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Score {
    string name;
    int korean;
    int english;
    int math;
};

Score students[100001];
int n;

bool cmp(Score a, Score b) {
    if (a.korean == b.korean && a.english == b.english && a.math == b.math) {
        return a.name < b.name;
    }

    if (a.korean == b.korean && a.english == b.english) {
        return a.math > b.math;
    }

    if (a.korean == b.korean) {
        return a.english < b.english;
    }

    return a.korean > b.korean;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
    }
    sort(students, students + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << students[i].name << "\n";
    }
}