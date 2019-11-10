#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Edge {
    int to;
    int w;
    int next;
}p[1000000];
int dis[20000], vis[20000], head[20000], k;
void add(int u,int v,int w) {
    p[++k].next = head[u];
	p[k].to = v;
	p[k].w = w;
	head[u] = k; 
}
int read() {
	int s = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') {
			f = -1;
		}
		c =  getchar();
	}
	while(c >= '0' && c <= '9') {
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}
int main() {
    int n,m,s;
    int a,b,c;
    n = read();
    m = read();
    s = read();
    for(int i = 1;i <= n;i++) {
    	dis[i]=2147483647;
	}
    for(int i = 0;i < m;i++) {
        a = read();
        b = read();
        c = read();
        add(a,b,c);
    }
    int cur = s;
    dis[s] = 0;
    long long int minn;
    while(!vis[cur]) {
        vis[cur] = true;
        for(int i = head[cur]; i != 0;i = p[i].next) {
            if(!vis[p[i].to] && dis[p[i].to] > dis[cur] + p[i].w) {
            	dis[p[i].to] = dis[cur] + p[i].w;
			}
        }
        minn = 2147483647;
        for(int i = 1;i <= n;i++) {
            if(!vis[i] && minn > dis[i]) {
                minn = dis[i];
                cur = i;
            }
        }
    }
    for(int i = 1;i <= n;i++ ) {
    	cout<<dis[i]<<" ";
	}
    return 0;
}
