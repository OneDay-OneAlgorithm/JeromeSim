#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<char> stack;
    string str, bomb;
    cin >> str;
    cin >> bomb;
    for (int i = 0; i < str.size(); i++) {
        stack.push_back(str[i]);
        if (stack.size() < bomb.size()) continue;
        bool flag = true;
        for (int j = 0; j < bomb.size(); j++) {
            if (stack[stack.size() - bomb.size() + j] != bomb[j]) flag = false;
        }
        if (flag) {
            for (int j = 0; j < bomb.size(); j++) stack.pop_back();
        }
    }
    if (stack.empty()) {
        cout << "FRULA";
    } else {
        for (int i = 0; i < stack.size(); i++) {
            cout << stack[i];
        }
    }
}