#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double pre[1010] = {0};

struct People {
    int id;
    double t;
};

People p[1010];

bool cmp(People a, People b) {
    if(a.t == b.t) return a.id < b.id;
    return a.t < b.t;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i].t;
        p[i].id = i;
    }
    sort(p + 1, p + n + 1, cmp);
    double sum = 0;
    for(int i = 1; i <= n; ++i) {
        if(i == 1)  printf("%d", p[i].id);
        else printf(" %d", p[i].id);
    }
    for(int i = 1; i <= n - 1; ++i) {
        pre[i] = pre[i - 1] + p[i].t;
        sum += pre[i];
    }
    sum = sum / (double)n;
    printf("\n%.2f\n", sum);
    return 0;
}