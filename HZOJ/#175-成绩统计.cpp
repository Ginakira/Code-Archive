#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, score, y = 0, l = 0, z = 0, c = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> score;
        if (score >= 90 && score <= 100)
            y++;
        else if (score >= 80)
            l++;
        else if (score >= 60)
            z++;
        else
            c++;
    }
    cout << "You " << y << endl << "Liang " << l << endl << "Zhong " << z << endl << "Cha " << c << endl;
    return 0;
}