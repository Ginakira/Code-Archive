#include<iostream>
#include<cstdio>
#include<string.h>
#define max 100000
using namespace std;
char s[max];
int a[max], b[max];
int main() {
	int d;
	scanf("%s",s);
	cin>>d;
	int len1 = strlen(s);    
    int yu = 0;          
    for(int i = 0;i <= len1 - 1;i++) {
    	a[i+1] = s[i] - '0';
	}         
    for(int i = 1;i <= len1;i++) {
        b[i] = (yu * 10 + a[i]) / d;
        yu = (yu * 10 + a[i]) % d;
    }
    int len2=1;
    while(b[len2] == 0 && len2 < len1) {
    	len2++;
	}
    for(int i = len2;i <= len1;i++) {
    	cout<<b[i];
	}     
	return 0;
}
