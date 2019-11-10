#include <iostream>
using namespace std;
int d[10] = {0};
void add(int a) {
    while(a != 0) {
        d[a % 10]++;
        a /= 10;
    }
    return ;
}

int main() {
    int m, n;
    cin >> m >> n;
    for(int i = m; i <= n; ++i) {
        add(i);
    }
    for(int i = 0; i < 9; ++i) {
        cout << d[i] << ' ';
    }
    cout << d[9] << endl;
    return 0;
}