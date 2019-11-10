#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool is_prime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b, cnt = 0;
    bool first = true;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i % 6 == 0) {
            int tmp = sqrt(i % 100);
            if (tmp * tmp == i % 100) {
                int tmp2 = i / 100;
                if (is_prime(tmp2)) {
                    if(!first) {
                        cout << ' ';
                    } else {
                        first = false;
                    }
                    cout << i;
                    cnt++;
                }
            }
        }
    }
    cout << endl << cnt << endl;
    return 0;
}