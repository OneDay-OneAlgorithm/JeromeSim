#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> removeFiles;
        set<string> s;
        int n1, n2, result = 0;
        cin >> n1;
        for (int i = 0; i < n1; i++) {
            string tmp;
            cin >> tmp;
            removeFiles.push_back(tmp);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++) {
            string tmp;
            cin >> tmp;
            string tmp2 = "";
            for (char j : tmp) {
                tmp2 += j;
                s.insert(tmp2);
            }
        }

        sort(removeFiles.begin(), removeFiles.end());

        for (int i = 0; i < removeFiles.size(); i++) {
            int maxSize = removeFiles.size();
            bool flag = false;
            string tmp = "";
            for (int j = 0; j < removeFiles[i].size(); j++) {
                tmp += removeFiles[i][j];
                for (int k = i + 1; k < maxSize; k++) {
                    if (removeFiles[k].size() <= j || removeFiles[k][j] != removeFiles[i][j]) {
                        maxSize = k;
                        break;
                    }
                }
                if (s.find(tmp) == s.end()) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                i += (maxSize - i - 1);
            }
            result++;
        }

        if (s.empty()) {
            cout << 1 << "\n";
        } else {
            cout << result << "\n";
        }

    }
}