#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    pair<string, int> opers[1001];
    int n, regi = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> opers[i].first;
        if (opers[i].first == "PUSH" || opers[i].first == "IFZERO") {
            cin >> opers[i].second;
        } else {
            opers[i].second = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (opers[i].first == "PUSH") {
            s.push(opers[i].second);
        } else if (opers[i].first == "STORE") {
            regi = s.top();
            s.pop();
        } else if (opers[i].first == "LOAD") {
            s.push(regi);
        } else if (opers[i].first == "PLUS") {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();
            s.push(first + second);
        } else if (opers[i].first == "TIMES") {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();
            s.push(first * second);
        } else if (opers[i].first == "IFZERO") {
            if (s.top() == 0) i = opers[i].second - 1;
            s.pop();
        } else if (opers[i].first == "DONE") {
            cout << s.top();
            return 0;
        }
    }
}