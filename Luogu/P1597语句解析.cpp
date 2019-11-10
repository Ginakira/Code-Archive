#include <iostream>
#include <cstdio>
using namespace std;

int a[3];
int main() {
    char c1, c2;
    while(scanf("%c:=%c;", &c1, &c2) == 2) {
        a[c1 - 'a'] = c2 >= '0' && c2 <= '9' ? c2 - '0' : a[c2 - 'a'];
    }
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    return 0;
}