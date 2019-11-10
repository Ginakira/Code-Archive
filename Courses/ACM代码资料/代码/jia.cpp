#include <iostream>
#include<string.h>
using namespace std;
char a1[3000],b1[3000];
int a[100000],b[100000],c[100000], lc = 1;
int main() {
    int la, lb;
    cin>>a1;
	cin>>b1;
    la=strlen(a1);
	lb=strlen(b1);
    for(int i = 0;i<la;i++){
      	a[la-i] = a1[i] - '0';
    }
    for(int i=0;i<lb;i++){
		b[lb-i]=b1[i]-'0';
    }
    int len = la > lb ? la : lb;
    int k = 0;
    while(lc <= len){
        c[lc] = a[lc] + b[lc] + k;
        k = c[lc] / 10;
        c[lc] %= 10;
        lc++;
    }
    c[lc] = k;
    while(c[lc] == 0 && lc > 1) lc--;
    for(int i = lc;i >= 1;i--){
        cout<<c[i];
    }
    return 0;
}