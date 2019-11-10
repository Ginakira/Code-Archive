#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void ans(int *a, int n) {
	int i, j, r, key;
	for(r  = n / 2; r >= 1;r /= 2) {
		for(i = r;i < n;++i) {
			key = a[i];
			j = i - r;
			while(j >= 0 && key < a[j]) {
				a[j+r] = a[j];
				j -= r;
			}
			a[j+r] = key;
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
