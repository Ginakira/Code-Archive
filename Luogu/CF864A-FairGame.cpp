#include <iostream>
using namespace std;

int main() {
    int n, tmp, p1 = 0, p2 = 0, c1 = 0, c2 = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp == p1) c1++;
        else if(tmp == p2) c2++;
        else if(p1 == 0) {
            p1 = tmp;
            c1++;
        }
        else if(p2 == 0) {
            p2 = tmp;
            c2++;
        }
    }
    if(n % 2 != 0) cout << "NO";
    else if(c1 == c2 && c1 * 2 == n) cout << "YES\n" << p1 << ' ' << p2;
    else cout << "NO";
    return 0;
}