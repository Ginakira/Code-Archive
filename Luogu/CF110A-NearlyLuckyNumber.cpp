#include <iostream>
typedef long long LL;
using namespace std;

bool judge(LL n) {
    LL tmp = n, fou = 0, sev = 0, sum;
    bool all = true;
    while(tmp > 0) {
        if(tmp % 10 == 4) fou++;
        else if(tmp % 10 == 7) sev++;
        else all = false;
        tmp /= 10;
    }
    sum = fou + sev;
    //cout << sum << endl;
    if(sum >= 10) return judge(sum);
    else if(sum == 4 || sum == 7) return true;
    else return false;
}

int main() {
    LL n;
    cin >> n;
    if(judge(n)) cout << "YES";
    else cout << "NO";
    return 0;
}