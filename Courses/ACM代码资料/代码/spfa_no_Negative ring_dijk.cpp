#include<iostream>
#include<queue>
#include<cstdio>
int inf=2147483647;
using namespace std;
int n,m,s,k=0;
int dis[10005],vis[10005],head[10005];
struct node {
  int v;
  int w;
  int next;
}p[500005]; 
void add(int u, int v, int w) {
	p[++k].next = head[u];
	p[k].v = v;
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
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}
void spfa() {
  queue<int> q; 
  for(int i = 1 ; i <= n; i++) {
    dis[i] = inf; 
    vis[i] = 0; 
  }
  q.push(s); 
  dis[s]=0; 
  vis[s] = 1; 
  while(!q.empty()) {
    int u = q.front(); 
    q.pop(); 
	vis[u]=0; 
    for(int i = head[u]; i; i = p[i].next) {
      int v = p[i].v ; 
      if(dis[v] > dis[u] + p[i].w ) {
        dis[v] = dis[u] + p[i].w ;
        if(vis[v]==0) {
          vis[v]=1; 
          q.push(v);
        }
      }
    }
  }
}
int main() {
  n = read();
  m = read();
  s = read();
  for(int i = 0 ; i < m; i++) {
    int a, b, c;
    a = read();
    b = read();
    c = read();
    add(a,b,c);
  }
  spfa();
  for(int i = 1; i <= n; i++) {
  	if(s == i) {
  		cout<<0<<" ";
	} else {
		cout<<dis[i]<<" "; 
	} 
  }
  return 0;
} 
