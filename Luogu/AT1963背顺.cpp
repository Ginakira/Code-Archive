#include <iostream>
#include <algorithm>
using namespace std;

struct Height {
    int id, h;
};

Height p[12333333];

bool cmp(Height a, Height b) {
    return a.h > b.h;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        p[i].id = i;
        cin >> p[i].h;
    }
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i <= n; ++i) {
        cout << p[i].id << endl;
    }
    return 0;
}