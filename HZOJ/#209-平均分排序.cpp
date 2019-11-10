#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

double score[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }
    sort(score, score + n);
    for (int i = 0; i < n; ++i) {
        cout << score[i] << endl;
    }
    return 0;
}