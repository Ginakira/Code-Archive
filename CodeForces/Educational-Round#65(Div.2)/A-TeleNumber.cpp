#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        size_t pos;
        if(n < 11) {
            cout << "NO" << endl;
            continue;
        }
        if(count(s.begin(), s.end(), '8') == 0) {
            cout << "NO" << endl;
            continue;
        }
        int op = n - 11;
        pos = s.find('8');
        if(pos <= op) {
            cout << "YES" << endl;
            continue;
        }
        else {
            cout << "NO" << endl;
            continue;
        }
    }
    return 0;
}