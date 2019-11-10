#include <iostream>
using namespace std;

int main() {
    int n, scp, sca;
    cin >> n;
    bool flag = false;
    string s;
    while(n--) {
        cin >> s >> scp >> sca;
        if(scp >= 2400 && sca > scp)
            flag = true;
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}