#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cfloat>
using namespace std;

struct Cheese {
    double x;
    double y;
};

Cheese c[20];
int n;
double ans = DBL_MAX;
bool vis[20] = {0};
double dis_save[20][20] = {0};

void DFS(int now, int cnt, double sum) {
    #define Dis(a, b) sqrt(pow((c[a].x - c[b].x), 2) + pow((c[a].y - c[b].y), 2))
    if(sum > ans) return ;
    if(cnt == n) {
        ans = min(ans, sum);
        return ;
    }
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        if(dis_save[now][i] == 0) dis_save[now][i] = Dis(now, i);
        vis[i] = true;
        DFS(i, cnt + 1, sum + dis_save[now][i]);
        vis[i] = false;
    }
    #undef Dis
    return ;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i].x >> c[i].y;
    }
    DFS(0, 0, 0);
    printf("%.2lf\n", ans);
    return 0;
}