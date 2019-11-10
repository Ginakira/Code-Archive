#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x1, y1, x2, y2, t, xa, ya;
    char c;
    int cnt[5] = {0};
    cin >> x1 >> y1 >> x2 >> y2 >> t;
    xa = x2 - x1;
    ya = y2 - y1;
    while(t--) {
        cin >> c;
        if(c == 'N') cnt[1]++;
        else if(c == 'S') cnt[2]++;
        else if(c == 'W') cnt[3]++;
        else cnt[4]++;
    }
    if(xa > 0 && cnt[4] < xa) {
        cout << -1 << endl;
        return 0;
    }
    else if(xa < 0 && cnt[3] < abs(xa)) {
        cout << -1 << endl;
        return 0;
    }
    else if(ya > 0 && cnt[1] < ya) {
        cout << -1 << endl;
        return 0;
    }
    else if(ya < 0 && cnt[2] < abs(ya)) {
        cout << -1 << endl;
        return 0;
    }
    cout << abs(xa + ya) << endl;
    return 0;
}