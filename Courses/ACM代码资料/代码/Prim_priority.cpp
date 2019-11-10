#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int k,n,m,cnt,sum,ai,bi,ci,head[5005],dis[5005],vis[5005];

struct node {
    int v,w,next;
}e[400005];

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
void add(int u,int v,int w) {
    e[++k].v = v;
    e[k].w=w;
    e[k].next=head[u];
    head[u]=k;
}

typedef pair <int,int> pii;
priority_queue <pii,vector<pii>,greater<pii> > q;

void prim() {
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty()&&cnt<n) {
        int d=q.top().first,u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        cnt++;
        sum += d;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].next) {
        	if(e[i].w<dis[e[i].v]) {
        		dis[e[i].v]=e[i].w,q.push(make_pair(dis[e[i].v],e[i].v));
			}
		}                         
    }
}

int main() {
    memset(dis,127,sizeof(dis));
    memset(head,-1,sizeof(head));
    n = read();
    m = read(); 
    for(int i = 1;i <= m;i++) {
        ai = read();
        bi = read();
        ci = read();
        add(ai,bi,ci);
        add(bi,ai,ci);
    }
    prim();
    if (cnt==n) {
    	printf("%d",sum);	
	} else {
		printf("orz");
	}
	return 0;
}
