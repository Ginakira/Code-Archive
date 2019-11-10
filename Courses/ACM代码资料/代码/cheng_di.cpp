#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#define max 100000
using namespace std;
char s[max];
int a[max], b[max];
int main() {
	int d;
	scanf("%s",s);
	cin>>d;
	int len = strlen(s);           
    for (int i = 0 ; i < len ; i++) {
    	a[len - i - 1] = s[i] - '0';
	}           
    int k = 0;
    for (int i = 0 ; i < len ; i++) {
        a[i] = a[i] * d + k;   
        k = a[i] / 10;     
        a[i] %= 10;
    }
    if (k != 0) {
        a[len] = k;       
        len++;          
        while (a[len - 1] >= 10) {
            a[len] = a[len - 1] / 10;   
            a[len - 1] %= 10;
            len++;     
        }
    }
    while (a[len - 1] == 0 && len > 1) {
    	len--; 
	}
    for (int i = len - 1 ; i >= 0; i--) {
    	cout<<a[i];
	}
	return 0;
}
