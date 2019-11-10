#include <iostream>
using namespace std;

int main() {
    int n, one = 0, two = 0, thr = 0, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp == 1)
            one++;
        else if(tmp == 2)
            two++;
        else
            thr++;
    }
    int maxn = 0;
    maxn = max(max(one, two), thr);
    cout << n - maxn;
    return 0;
}