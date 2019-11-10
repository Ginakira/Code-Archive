#include<iostream>
using namespace std;
int n, l = 1, b[100010], g[1000010];
void many_count_cheng_di(int x) {
    for(int i = 1;i <= l;i++) {
    	g[i] *= b[x];	
	}
    for(int i = 1;i <= l;i++) {
        g[i+1] += g[i] / 10;
        g[i] %= 10;
    }
    l++;
    while(g[l] >= 10) {
        g[l+1] += g[l] / 10;
        g[l] %= 10;
        l++;
    }
    if(g[l] == 0) l--;
}
int main() {
    cin>>n;
    for(int i = 0;i < n;++i) {
    	cin>>b[i];
	}
	g[1] = b[0];
    for(int i=1;i<n;i++) {
    	many_count_cheng_di(i);
	}
    for(int i = l;i >= 1;i--) {
    	cout<<g[i];
	}
    return 0;
}
