#include<iostream>

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B; 
    if (N > B) cout << "Bus";
    else if (A > B) cout << "Subway";
    else if (A < B) cout << "Bus";
    else cout << "Anything";
}