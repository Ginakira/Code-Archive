#include<iostream>
#include<string.h>
#define maxn 100000
using namespace std;
int prime[maxn];  
bool is_prime[maxn];
int sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i){   
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = i + i; j <= n; j += i)  //  轻剪枝，j必定是i的倍数
                is_prime[j] = false;
        }
    }
    return p;  
}
int main() {
	sieve(10000);
	for(int i = 0;i < 10;++i) {
		if(is_prime[i]) {
			cout<<i<<endl;
		}
	}
	return 0;
}
