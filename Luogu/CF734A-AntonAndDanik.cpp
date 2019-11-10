#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, d, a;
    string s;
    cin >> n >> s;
    a = count(s.begin(), s.end(), 'A');
    d = count(s.begin(), s.end(), 'D');
    if(a > d) cout << "Anton";
    else if(d > a) cout << "Danik";
    else cout << "Friendship";
    return 0;
}