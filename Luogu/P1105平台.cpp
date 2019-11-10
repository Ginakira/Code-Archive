#include <iostream>
#include <algorithm>
using namespace std;

struct Platform {
    int id, h, l, r, fl, fr;
};

Platform p[1010];

bool cmp(Platform a, Platform b) {
    if(a.h == b.h) return a.id < b.id;
    return a.h > b.h;
}

bool cmp2(Platform a, Platform b) {
    return a.id < b.id;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        p[i].id = i;
        cin >> p[i].h >> p[i].l >> p[i].r;
        p[i].fl = 0;
        p[i].fr = 0;
    }
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(p[i].l < p[j].r && p[i].l > p[j].l) {
                p[i].fl = p[j].id;
                break;
            }
        }
        for(int j = i + 1; j <= n; ++j) {
            if(p[i].r < p[j].r && p[i].r > p[j].l) {
                p[i].fr = p[j].id;
                break;
            }
        }
    }
    sort(p + 1, p + n + 1, cmp2);
    for(int i = 1; i <= n; ++i) {
        cout << p[i].fl << ' ' << p[i].fr << endl;
    }
    return 0;
}