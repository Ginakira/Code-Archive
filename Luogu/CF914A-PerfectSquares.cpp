#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

bool jud(int n) {
    int tmp = sqrt(n);
    if(tmp * tmp == n)
        return false;
    else
        return true;
}

int main() {
    int n, t, maxt = INT_MIN;
    cin >> n;
    while(n--) {
        cin >> t;
        if(jud(t))
            maxt = max(maxt, t);
    }
    cout << maxt;
    return 0;
}