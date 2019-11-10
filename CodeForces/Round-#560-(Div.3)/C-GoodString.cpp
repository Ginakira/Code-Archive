#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int k = 0;
    for(int i = 0; i < s.length(); i += 2) {
        while(s[i] == s[i + 1]) {
            s.erase(i + 1, 1);
            k++;
        }
    }
    if(s.length() % 2 == 1) {
        s.erase(s.length() - 1, 1);
        k++;
    }
    cout << k << endl;
    cout << s << endl;
    return 0;
}