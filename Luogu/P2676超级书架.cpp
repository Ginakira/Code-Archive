#include <iostream>
#include <algorithm>
using namespace std;

int h[20001];
int main() {
    int n, b, sum = 0;
    cin >> n >> b;
    for(int i = 0; i < n; ++i)  cin >> h[i];
    sort(h, h + n, greater<int>());
    int j = 1;
    for(int i = 0; i < n; ++i) {
        sum += h[i];
        if(sum >= b) break;
        ++j;
    }
    cout << j << '\n';

    return 0;
}