#include <iostream>
#include <string>
using namespace std;

int main() {
    int m;
    string n;
    cin >> m >> n;
    for(int i = 0; i < n.length(); ++i) {
        if(i != 0 && n[i] != '0') cout << '+';
        if(n[i] == '0') continue;
        cout << n[i] << '*' << m << '^' << n.length() - i - 1;
    }
    return 0;
}