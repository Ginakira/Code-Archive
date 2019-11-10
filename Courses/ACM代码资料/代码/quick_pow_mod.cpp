#include<iostream>
using namespace std;
typedef long long int ll; 
int qpowmod(ll a, ll b, ll m) {
    ll ans = 1, base = a;
    while(b > 0) {
        if(b & 1) {
            ans *= base;
            ans %= m;
        }
        base *= base;
        base %= m;
        b >>= 1;
    }
    return ans % m;
}
int main() {
	ll a, b, m;
	cin>>a>>b>>m;
	ll c = qpowmod(a,b,m);
	cout<<c;
    return 0;
} 


