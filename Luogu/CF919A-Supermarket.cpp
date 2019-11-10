#include <iostream>
#include <cstdio>
using namespace std;

double mar;

int main() {
    int n, m;
    cin >> n >> m;
    double mins = 233;
    double a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        mar = a / b;
        mins = min(mins, mar);
    }
    printf("%.8f", mins * m);
    return 0;
}