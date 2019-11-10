#include <iostream>
using namespace std;

int cnt[10];

void cal(int a) {
    while(a > 0) {
        cnt[a % 10]++;
        a /= 10;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cal(i);
    }
    for(int i = 0; i < 10; ++i) {
        cout << cnt[i] << endl;
    }
    return 0;
}