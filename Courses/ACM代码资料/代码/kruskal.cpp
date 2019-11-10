#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int read() {
    int s = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
    	if(c == '-') {
    		f = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}
struct node{
    int u;
	int v;
	int w;
}p[200005];
int f[5005];
int cmp(node a,node b) {
    return a.w < b.w;
}
int find(int x) {
    if(f[x] == x) {
    	return x;
	} 
	return f[x] = find(f[x]);
}
int kruskal(int m, int n) {
	int num = 0, ans = 0;
    sort(p,p+m,cmp);
    for(int i = 0;i < m;i++) {
        int fu = find(p[i].u);
		int fv = find(p[i].v);
        if(fu == fv) {
            continue;
        }
        ans += p[i].w;
        f[fu] = fv;
        if(++num == n - 1) {
            break;
        }
    }
    return ans;
}
int main() {
	int n, m;
    n = read();
	m = read();
    for(int i = 1;i <= n;i++) {
        f[i] = i;
    }
    for(int i = 0;i < m;i++) {
        p[i].u = read();
		p[i].v = read();
		p[i].w = read();
    }
    int ans = kruskal(m,n);
    cout<<ans<<endl;
    return 0;
}
