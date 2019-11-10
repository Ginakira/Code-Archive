#include <cstring>
#include<iostream>
using namespace std;
char s[10000];
int a[10000];
int d,len;                           
int main() {
    int n, i;
    cin>>n;
    for(int m = 0;m < n;++m) {
    	if(m == 0) {
    		cin>>s;
    		len = strlen(s);
			for (int i = 0 ; i < len ; i++) {
				a[len - i - 1] = s[i] - '0';
			}  
		} else {
			cin>>d;
			int jinwei = 0;
			for (int i = 0 ; i < len ; i++) {
				a[i] = a[i] * d + jinwei;    
				jinwei = a[i] / 10;     
				a[i] %= 10;
			}
			if (jinwei != 0) {
				a[len] = jinwei;       
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
		}
	}
	for(int i = len - 1 ; i >= 0; i--) {
		cout<<a[i];
	}
	return 0;
}

