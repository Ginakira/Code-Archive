#include <iostream>
typedef long long LL;
using namespace std;

bool ispr(LL num) {
    if(num == 1 || num == 0)
        return false;
    if(num == 2)
        return true;
    for (LL i = 2; i * i <= num; ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    LL n;
    cin >> n;
    for (LL i = 2; i; ++i) {
        if(!ispr(i) && !ispr(n - i)) {
            cout << i << ' ' << n - i;
            return 0;
        }
    }
        return 0;
}