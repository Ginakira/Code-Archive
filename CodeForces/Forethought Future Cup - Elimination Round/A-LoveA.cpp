#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int anum;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'a') anum++;
    }
    int goal = s.length() / 2 + 1;
    if(anum >= goal) {
        cout << s.length() << endl;
        return 0;
    }
    else {
        cout << anum * 2  - 1 << endl;
        return 0;
    }
}