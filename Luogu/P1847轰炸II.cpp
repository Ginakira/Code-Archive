#include <iostream>
typedef long long LL;
using namespace std;

struct bpoint {
    LL x1, x2, y1, y2;
    LL rd;
};

bpoint bp[2020];

LL finx, finy, m, n, fint[2020] = {0}, finr[2020] = {0};

int main() {
    cin >> m >> n;
    for(LL i = 0; i < m; ++i) {
        cin >> bp[i].x1 >> bp[i].y1 >> bp[i].x2 >> bp[i].y2;
        bp[i].rd = i + 1;
    }
    for(LL i = 0; i < n; ++i) {
        cin >> finx >> finy;
        for(LL j = 0; j < m; ++j) {
            if(finx >= bp[j].x1 && finx <= bp[j].x2 && finy >= bp[j].y1 && finy <= bp[j].y2) {
                fint[i]++;
                finr[i] = bp[j].rd;
            }
        }
    }
    for(LL i = 0; i < n; ++i) {
        if(fint[i] == 0) cout << "NO" << endl;
        else {
            cout << "YES " << fint[i] << ' ' << finr[i] << endl;
        }
    }
    return 0;
}