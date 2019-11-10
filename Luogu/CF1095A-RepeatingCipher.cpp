#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, cnt;
    string s;
    cin >> n;
    int tmp = 0;
    for(int i = 1; tmp != n; ++i) {
        tmp += i;
        cnt = i;
    }
    char c;
    for(int i = 1; i <= cnt; ++i) {
        for(int j = 1; j <= i; ++j) cin >> c;
        s += c;
    }
    cout << s << endl;
    return 0;
}