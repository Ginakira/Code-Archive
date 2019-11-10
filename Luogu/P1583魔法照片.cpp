#include <iostream>
#include <algorithm>
using namespace std;

struct People {
    int w, d, num;
};

People p[20010];
int e[12];

bool cmp(People a, People b) {
    if(a.w == b.w) return a.num < b.num;
    return a.w > b.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= 10; ++i) cin >> e[i];
    for(int i = 1; i <= n; ++i) {
        cin >> p[i].w;
        p[i].num = i;
    }
    sort(p + 1, p + n + 1, cmp);
    //for(int i = 1; i <= n; ++i) cout << p[i].w << endl;
    for(int i = 1; i <= n; ++i) {
        p[i].d = (i - 1) % 10 + 1;
        p[i].w += e[p[i].d];
    }
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i < k; ++i) cout << p[i].num << ' ';
    cout << p[k].num << '\n';
    return 0;
}