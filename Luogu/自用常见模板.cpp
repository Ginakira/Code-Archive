#include <iostream>
using namespace std;
typedef long long LL;

LL qPow(LL a, LL b, LL m = 1) {
    //快速幂（取余）模板 a为底 b为幂 m为除数
    LL ans = 1, base = a;
    while(b > 0) {
        if(b & 1) {
            ans *= base;
            ans %= m;
        }
        base *= base;
        base %= m;
        b >>= 1;
    }
    return ans;
}

//并查集模板
//pre维护每个节点的父节点 rk维护子节点个数
int pre[2333], rk[2333];
void init(int n) {
    for(int i = 0; i <= n; ++i) {
        pre[i] = i;
        rk[i] = 1;
    }
    return ;
}

//带路径压缩的父节点查找 将每个节点的父节点变为根节点
int find(int key) {
    if(pre[key] == key) return key;
    return pre[key] = find(pre[key]);
}

//合并两个子节点
void merge(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if(roota != rootb) {
        pre[rootb] = roota;
        rk[roota] += rk[rootb];
    }
    return ;
}


//一维01背包模板
//w存储代价 v存储价值 n物品数量 t背包容量
int dp[2333], w[2333], v[2333], n, t;
void Knapsack() {
    for(int i = 1; i <= n; ++i) {
        for(int j = t; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    //dp[背包容量]即为最终结果
    cout << dp[t] << endl;
    return ;
}

//一维完全背包模板
//w存储代价 v存储价值 n物品数量 t背包容量
int dp[2333], w[2333], v[2333], n, t;
void Knapsack() {
    for(int i = 1; i <= n; ++i) {
        for(int j = w[i]; j <= t; ++j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    //dp[背包容量]即为最终结果
    cout << dp[t] << endl;
    return ;
}