#include<iostream>
using namespace std;
int f[10010];
int find(int k){
    if(f[k] == k) {
    	return k;
	}
    return f[k] = find(f[k]);
}
int main() {
	int i, n, m, p1, p2, p3;
    cin>>n>>m;
    for(i = 1;i <= n;i++) {
    	f[i] = i;
	}
    for(i = 1;i <= m;i++){
        cin>>p1>>p2>>p3;
        if(p1 == 1) {
        	f[find(p2)] = find(p3);
		} else {
			if(find(p2) == find(p3)) {
				cout<<"Y\n";
			} else {
				cout<<"N\n";
			}
		}
    }
    return 0;
}