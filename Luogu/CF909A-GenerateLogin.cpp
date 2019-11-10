#include <iostream>
using namespace std;

int main() {
    string a, b, fin;
    cin >> a >> b;
    fin += a[0];
    for(int i = 1; i < a.length(); ++i) {
        if(a[i] < b[0]) fin += a[i];
        else break;
    }
    fin += b[0];
    cout << fin;
    return 0;
}