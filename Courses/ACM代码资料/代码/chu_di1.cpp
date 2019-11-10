#include<iostream>
using namespace std;
int g[1000010], l = 1;
void chu_di(int x) {
    for(int i = l;i >= 1;i--) {
        g[i-1] += ((g[i] % x) * 10);
        g[i] /= x;
    }
    while(g[l] == 0) l--;
    if(l == 0) {
    	cout<<"1"<<endl;
	}
}
void many_count_cheng_di(int x) {
    for(int i = 1;i <= l;i++) {
    	g[i] *= x;	
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
	int n, d;
    cin>>n>>d;
    g[1] = 1;
    many_count_cheng_di(n);
    chu_di(d);
    for(int i = l;i >= 1; i--) {
    	cout<<g[i];
	}
    return 0;
}
