#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int tree[500100];
int lowbit(int x){
    return x & -x;
}
void add(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    int now = 0;
    for(int i=1;i<=n;i++) {
    	int a;
    	cin>>a;
    	add(i,a-now);
    	now = a;
	}
	for(int i=1;i<=m;i++){
    	int a;
    	scanf("%d",&a);
    	if(a==1){
        	int x,y,z;
        	scanf("%d%d%d",&x,&y,&z);
       	 	add(x,z);
        	add(y+1,-z);
    	}
    	if(a==2){
        	int x;
        	scanf("%d",&x);
        	printf("%d\n",sum(x));
    	}
	}
	return 0;
}
