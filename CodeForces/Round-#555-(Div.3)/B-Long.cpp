#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string a;
    bool sub = true;
    int f[10];
    cin >> n >> a;
    for(int i = 1; i < 10; ++i) {
        cin >> f[i];
    }
    for(int i = 0; i < n; ++i) {
        if(f[a[i] - '0'] <= a[i] - '0' || !sub) cout << a[i];
        if(f[a[i] - '0'] > a[i] - '0' && sub) {
            cout << f[a[i] - '0'];
            if(f[a[i + 1] - '0'] < a[i + 1] - '0') {
                sub = false;
            }
        }
    }
    cout << endl;

}