#include <iostream>
using namespace std;

int main() {
    int n, u, d;
    while(cin >> n >> u >> d) {
        if (n == 0) break;
        int day = 0;
        while (n > 0) {
            if (++day % 2 != 0) n -= u;
            else n += d;
        }
        cout << day << endl;
    }
    return 0;
}