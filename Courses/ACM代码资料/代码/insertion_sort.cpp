#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void ans(int *a, int n) {
	int i, j, key;
	for(i = 1;i < n;++i) {
		j = i - 1;
		key = a[i];
		while(j >= 0 && key < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
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
