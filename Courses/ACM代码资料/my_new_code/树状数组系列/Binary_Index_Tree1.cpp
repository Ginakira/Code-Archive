#include <iostream>
#include <cstdio>
using namespace std;
int n,m,tree[2000010];
int lowbit(int k) {
    return k & -k;
}
void add(int x,int k) {
    while(x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
}
int sum(int x){
    int ans = 0;
    while(x != 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
            add(b,c);//将某一个数加上x
        if(a==2)
            cout<<sum(c)-sum(b-1)<<endl; //求出某区间每一个数的和
    }
}
//Cn = A(n – 2^k + 1) + ... + An
//设节点编号为x，那么这个节点管辖的区间为2^k（其中k为x二进制末尾0的个数）个元素
