#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    for(int i = 0; i < n; ++i) {
        if(s2[i] > s1[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << s2;
    return 0;
}