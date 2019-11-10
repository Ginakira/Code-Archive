#include<iostream>
#include<string.h>
#include<cstdio>
#define max 1000000
using namespace std;
int x[max],y[max],z[max]; 
int main() { 
	int n;
	char arr1[max];
	char arr2[max];
	int len, j, k, l;
	cin>>n;
	for(int i = 0;i < n;++i) {
		memset(arr2,'\0',sizeof(arr2));
		if(i == 0) {
			cin>>arr1;
			for(k = 0, l = strlen(arr1) - 1;l >= 0;--l) {
				z[k++] = arr1[l] - '0';
			}	
		} else {
			cin>>arr1;
			for(k = 0;k < len;++k) {
				y[k] = z[k];
			}
			memset(z,0,sizeof(z));
			for(j = 0,k = strlen(arr1) - 1;k >= 0;k--) {
				x[j++] = arr1[k] - '0';
			}
			for(k = 0;k < strlen(arr1);k++) {
				for(j = 0;j < len;j++)
					z[k+j] += x[k] * y[j]; 
			}
			for(k = 0;k < max;k++) {
				if(z[k] >= 10) {
					z[k+1] += z[k] / 10;  
					z[k] %= 10;  
				}
			}
			for(k = max; k > 0;k--) {
				if(z[k]==0) {
					continue;
				} else {
					break;
				}
	    	}
		}
		len = k;	
	}
	for(k = len; k > 0;k--) {
		if(z[k]==0) {
			continue;
		} else {
			break;
		}
	}	
	for(;k >= 0;k--) {
		cout<<z[k];
	}
	cout<<endl;
	return 0;
}


