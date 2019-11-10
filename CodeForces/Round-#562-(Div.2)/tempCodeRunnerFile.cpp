#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    bool same = false, dl = false, vl = false;
    for(int i = a, j = b; !dl & !vl; ++i, --j) {
        if(i > n) i = 1;
        if(j < 0) j = n;
        //cout << "#" << i << " #" << j << endl;
        if(i == j) same = true;
        if(i == x) dl = true;
        if(j == y) dl = true;
    }
    if(same) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}