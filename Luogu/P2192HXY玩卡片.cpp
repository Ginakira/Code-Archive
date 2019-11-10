#include <iostream>
using namespace std;

int num[1001];

int main() {
    int n, sum = 0;
    cin >> n;
    int zero = 0, five = 0;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if(t == 0) zero++;
        else five++;
    }
    if(zero == 0) {
        cout << -1 << endl;
        return 0;
    }
    else if(five < 9 && zero != 0) {
        cout << 0 << endl;
    }
    else {
        int cnt = five - five % 9;
        for(int i = 0; i < cnt; ++i) cout << 5;
        for(int i = 0; i < zero; ++i) cout << 0;
        cout << endl;
        return 0;
    }
    return 0;
}