#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void ans(int *a, int n) {
	int i, j, key;
	for(i = 0;i < n - 1;++i) {
		key = i;
		for(j = i + 1;j < n;++j) {
			if(a[key] > a[j]) {
				key = j;
			}
		}
		if(key != i ) {
			int t = a[i];
			a[i] = a[key];
			a[key] = t;
		}
	}
} 
int main() {
	srand((unsigned long)time(0));
	int a[10];
	for(int i = 0; i < 10;++i) {
		a[i] = rand()%1231;
	}
	ans(a,10);
	for(int i = 0; i < 10;++i) {
		cout<<a[i]<<" ";
	}
	return 0;
}
