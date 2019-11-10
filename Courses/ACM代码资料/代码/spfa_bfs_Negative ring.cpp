#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<queue>
#include<string.h>
#define N 100086
#define clear(a) memset(a,0,sizeof a)
#define rk for(register int  i=1;i<=n;i++)
using namespace std;
inline int read(){
    register int x = 0, f = 1;
	char ch = getchar();
    while(ch < '0' || ch > '9') { 
		if(ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
    while(ch <= '9' && ch >= '0') {
    	x = x * 10 + ch - '0';
		ch = getchar();	
	}
    return f * x;
}
int n, m, T;
struct node {
	int next, v, w;
}p[N<<1];
bool vis[N];
int head[N],k,dis[N],cnt[N];
inline void add(int u,int v,int w) {
	p[++k].next = head[u];
	p[k].v = v;
	p[k].w = w;
	head[u] = k;
}
bool spfa(int now) {
    rk vis[i]=0,dis[i]=2147483647,cnt[i]=0;
    queue<int>q;
    q.push(now);
    vis[now]=true;
    dis[now]=0;
    while(!q.empty()) {
        register int u=q.front();
		q.pop();
		vis[u] = 0;
        if(cnt[u]>=n) {
        	return 1;
		}
        for(register int i=head[u];i;i=p[i].next ) {
            if(dis[p[i].v] > dis[u] + p[i].w) {
                dis[p[i].v] = dis[u] + p[i].w;
                if(!vis[p[i].v]){
                    q.push(p[i].v);
                    vis[p[i].v]=1;
                    cnt[p[i].v]++;
                    if(cnt[p[i].v]>=n) {
                    	return 1;
					}
                }
            }
        }
    }
    return 0;
}
int main() {
    int t, u, v, w;
    t = read();
    while(t--) {
        n = read();
		m = read();
        k = 0;
		clear(head);
        for(register int i=1;i<=m;i++) {
            u = read();
			v = read();
			w = read();
            add(u,v,w);
            if(w >= 0) {
            	add(v,u,w);
			}
        }
        if(spfa(1)) {
        	cout<<"YE5"<<endl;
		} else {
			cout<<"N0"<<endl;
		}
    }
}
