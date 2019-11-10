#include <iostream>
#include <algorithm>
using namespace std;

int s[100001];

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n);
    return 0;
}