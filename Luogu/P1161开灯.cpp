#include <iostream>
using namespace std;

bool led[10000000] = {0};
int main() {
    int n;
    cin >> n;
    double a;
    int t, tmp, max = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a >> t;
        for(int j = 1; j <= t; ++j) {
            tmp = a * j;
            if(tmp > max) max = tmp;
            led[tmp] = !led[tmp];
        }
    }
    for(int i = 1; i <= max + 10; ++i) {
        if(led[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}