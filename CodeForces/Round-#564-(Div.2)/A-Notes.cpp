#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if(z == 0) {
        if (x > y) cout << '+' << endl;
        else if(x < y) cout << '-' << endl;
        else cout << 0 << endl;
        return 0;
    }
    int up, dw;
    up = x + z >= y ? 1 : 0;
    dw = y + z >= x ? 1 : 0;
    //cout << up << ' ' << dw << endl;
    if(up && dw) cout << "?" << endl;
    else if(up) cout << "+" << endl;
    else if(dw)cout << '-' << endl;
    return 0;
}