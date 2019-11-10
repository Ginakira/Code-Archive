#include <iostream>
using namespace std;

int f[5050];

int main() {
    int n, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }
    bool exs = false;
    for (int i = 1; i <= n; ++i) {
        a = f[i];
        b = f[a];
        c = f[b];
        if(c == i) {
            exs = true;
            break;
        }
    }
    if(exs)
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}