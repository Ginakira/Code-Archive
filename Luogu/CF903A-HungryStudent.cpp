#include <iostream>
using namespace std;

int main() {
    int n, x;
    bool flag;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        flag = false;
        cin >> x;
        for (int i = 0; i <= x / 7; ++i) {
            if((x - i * 7) % 3 == 0) {
                cout << "YES\n";
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "NO\n";
    }
    return 0;
}