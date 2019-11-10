#include <cmath>
#include <iostream>
#include <set>
using namespace std;

set<string> s;

string calEnd(int)

int main() {
    int n, k;
    bool repeat = false;
    cin >> n >> k;
    int tmp, cnt = 1, end;
    while (!repeat) {
        tmp = pow(n, cnt);
        end = tmp % (100 * k);
    }
    return 0;
}
