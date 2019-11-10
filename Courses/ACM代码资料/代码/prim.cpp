#include<iostream>
#include<cstdio>
#include<stdlib.h>
#define inf 123456789
#define maxn 5005
#define maxm 200005
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
struct edge {
    int v,w,next;
}e[maxm<<1];

int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
bool vis[maxn];
void add(int u,int v,int w) {
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int prim() {
    for(int i=2;i<=n;++i){
        dis[i]=inf;
    }
    for(int i=head[1];i;i=e[i].next) {
        dis[e[i].v]=min(dis[e[i].v],e[i].w);
    }
    while(++tot<n){
        int minn=inf;
        vis[now]=1;
        for(int i=1;i<=n;++i){
            if(!vis[i]&&minn>dis[i]){
                minn=dis[i];
                now=i;
            }
        }
        ans+=minn;
        for(int i=head[now];i;i=e[i].next) {
            int v=e[i].v;
            if(dis[v]>e[i].w&&!vis[v]){
                dis[v]=e[i].w;
            }
        }
    }
    return ans;
}
int main() {
    n = read();
	m = read();
	int u, v, w;
    for(int i = 1;i <= m;++i) {
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    printf("%d",prim());
    return 0;
}
