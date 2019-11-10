#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int mark[10000][10000];

int main() {
    int al, ar, au, ad, bl, br, bu, bd;
    int cnt = 0;
    cin >> al >> ar >> au >> ad >> bl >> br >> bu >> bd;
    for (int i = al + 1; i <= ar; ++i) {
        for (int j = au + 1; j <= ad; ++j) {
            mark[i][j]++;
        }
    }
    for (int i = bl + 1; i <= br; ++i) {
        for (int j = bu + 1; j <= bd; ++j) {
            if (mark[i][j] > 0) {
                mark[i][j]++;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}