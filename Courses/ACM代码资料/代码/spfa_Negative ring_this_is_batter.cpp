#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#define N 100086
#define clear(a) memset(a,0,sizeof(a))
using namespace std;
int read(){
    int x = 0, f = 1;
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

int n, m, s;
struct node {
	int next, v, w;
}p[N<<1];
bool vis[N];
int head[N], k, dis[N], cnt[N], q[N];
void add(int u,int v,int w) {
	p[++k].next = head[u];
	p[k].v = v;
	p[k].w = w;
	head[u] = k;
}
int spfa(int s) {
    int l, r;
    l = r = 0;
    memset(dis,63,sizeof dis);
    clear(vis);
	clear(cnt);
	clear(q);
    vis[s] = 1;
	cnt[s] = 1;
	dis[s] = 0;
    q[r++] = s;
    while(l != r) {
        int u = q[l++];
        if(l > n) {
        	l = 0;
		}
        vis[u] = 0;
        for(int i = head[u]; i ;i = p[i].next ) {
            if(dis[p[i].v] > dis[u] + p[i].w) {    
                dis[p[i].v] = dis[u] + p[i].w;
                cnt[p[i].v] = cnt[u] + 1;
                if(cnt[p[i].v] >= n && p[i].w < 0) {
                	return 1;
				}
                if(!vis[p[i].v]) {
                    vis[p[i].v] = 1;
                    if(dis[p[i].v]>dis[q[l]]) {
                        l--;
                        if(l<0) {
                        	l = n;
						}
                        q[l] = p[i].v;
                    } else {
                        q[r++]=p[i].v;
                        if(r>n) {
                        	r = 0;
						}
                    }
                }
            }
        }
    }
    return 0;
}
int main(){
	int t, u, v, w;
    t = read();
    while(t--){
        s = 1;
		k = 0;
		clear(head);
        n = read();
		m = read();
        for(int  i = 0;i < m;i++){
            u = read();
			v = read();
			w = read();
            add(u,v,w);
            if(w >= 0) {
            	add(v,u,w);
			}
        }
        if(spfa(s)) {
        	cout<<"YE5"<<endl;
		} else {
			cout<<"N0"<<endl;
		}
    }
    return 0;
}
