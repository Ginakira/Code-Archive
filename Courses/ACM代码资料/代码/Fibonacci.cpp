#include<iostream>
#include<cstdio>
using namespace std;
int fib(int n) {
	if(n == 1 || n == 2) {
		return 1;
	} 
	long long int one = 1;
	long long int two = 1;
	long long int now;
	int i;
	for(i = 2; i < n; i++) {
		now = one + two;
		one = two;
		two = now;
	}
	return now;
}
int main() {
	int n;
	while(scanf("%d",&n) != EOF) {
		printf("%lld\n",fib(n));
	}
	return 0;
}
