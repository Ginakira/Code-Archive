#include<iostream>
#include<cstdio>
#define max1 300000
using namespace std;
int a[max1], ans;
int main() {
	int n, sum = 0;
	cin>>n;
	for(int i = 0;i < n;++i) {
		cin>>a[i];
	} 
	sum = a[0];
	ans = a[0];
	for(int i = 1;i < n;++i) {
		if(sum < 0) {
			sum = 0;
		}
		sum += a[i];
		ans = ans > sum ? ans : sum;
	}
	cout<<ans;
	return 0;
}
