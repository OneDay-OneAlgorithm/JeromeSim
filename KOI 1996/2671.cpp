#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    bool flag = true;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            if (i == str.size() - 1 || str[i + 1] != '1') {
                flag = false;
                break;
            }
            i++;
        } else {
            if (i < str.size() - 2 && str[i + 1] == '0' && str[i + 2] == '0') {
                i += 3;

                if (i >= str.size()) {
                    flag = false;
                    break;
                }

                while (i < str.size() && str[i] == '0') {
                    i++;
                }

                if (i >= str.size()) {
                    flag = false;
                    break;
                }

                int cnt = 0;

                while (i < str.size() && str[i] == '1') {
                    i++;
                    cnt++;
                }

                i--;

                if (cnt == 1) continue;

                if (i < str.size() - 2 && str[i + 1] == '0' && str[i + 2] == '0') i--;
            } else {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        cout << "SUBMARINE";
    } else {
        cout << "NOISE";
    }
}