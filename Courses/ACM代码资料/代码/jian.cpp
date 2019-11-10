#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#define max 100000
using namespace std;
char s1[max], s2[max];
int a[max], b[max];
int main() {
	scanf("%s",s1);
	scanf("%s",s2);
	int len1 = strlen(s1);    
    int len2 = strlen(s2);
    int flag = 0;        
	int len;      
    if ( len1 < len2 || (strcmp(s1,s2) < 0 && len1 == len2) ) {                                           
        flag = 1; 
        for (int i = len2 - 1 ; i >= 0 ; i--)   
            a[len2 - i - 1] = s2[i] - '0';       
        for (int i = len1 - 1 ; i >= 0 ; i--)
            b[len1 - i - 1] = s1[i] - '0';
    } else {
        for (int i = len1 - 1 ; i >= 0 ; i--) 
            a[len1 - i - 1] = s1[i] - '0';
        for (int i = len2 - 1 ; i >= 0 ; i--)
            b[len2 - i - 1] = s2[i] - '0';
    }
    len = len1 > len2 ? len1 : len2;
    for (int i = 0 ; i < len ; i++)
    {
        a[i] -= b[i];     
        if (a[i] < 0) {
            a[i+1] -= 1;        
            a[i] += 10;          
        }
    }
    while (a[len - 1] == 0 && len > 1) {
    	len--;
	}
    if (flag == 1) {
    	cout<<"-";
	}      
    for (int i = len - 1 ;i >= 0 ;i--)   
        cout<<a[i];
	return 0;
}
