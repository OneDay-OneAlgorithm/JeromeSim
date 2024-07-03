#include <iostream>
#include <string>
using namespace std;

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    string a, b, c;
    int num = 0;
    cin >> a >> b >> c;
    if (isDigit(a[0])) num = stoi(a) + 3;
    else if (isDigit(b[0])) num = stoi(b) + 2;
    else if (isDigit(c[0])) num = stoi(c) + 1;

    if (num % 5 == 0 && num % 3 == 0) cout << "FizzBuzz";
    else if (num % 5 == 0) cout << "Buzz";
    else if (num % 3 == 0) cout << "Fizz";
    else cout << num;
}