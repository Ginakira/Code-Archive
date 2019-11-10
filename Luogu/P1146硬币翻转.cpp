#include <iostream>
using namespace std;

bool a[110] = {0};
int main() {
    int n;
    cin >> n;
    cout << n << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(j == i) cout << a[j];
            else {
                a[j] = !a[j];
                cout << a[j];
            }
        }
        cout << endl;
    }
    return 0;
}