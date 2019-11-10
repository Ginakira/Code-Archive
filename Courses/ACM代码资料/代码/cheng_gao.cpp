#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#define max 100000
using namespace std;
char s1[max], s2[max];
int a[max], b[max], c[max];
int main() {
	scanf("%s",s1);
	scanf("%s",s2);
	int len1 = strlen(s1);    
    int len2 = strlen(s2);
    int len;
    for (int i = 0 ; i < len1 ; i++)
        a[len1 - i - 1] = s1[i] - '0';    
    for (int i = 0 ; i < len2 ; i++)
        b[len2 - i - 1] = s2[i] - '0';
    for (int i = 0 ; i < len1 ; i++)
        for (int j = 0 ; j < len2 ; j++)
            c[i + j] += a[i] * b[j];        
    len = len1 + len2 - 1;    
    for (int i = 0 ; i < len ;i++) {
        c[i + 1] += c[i] / 10;    
        c[i] %= 10;
    }
    if (c[len] > 0) len++;    
    while (c[len - 1] >= 10) {
        c[len] = c[len - 1] / 10;
        c[len - 1] %= 10;
        len++;
    }
    while (c[len - 1] == 0 && len > 1) {
    	len--;
	}
    for (int i = len - 1; i >= 0 ; i--) {
    	cout<<c[i];
	}   
	return 0;
}
