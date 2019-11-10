#include <iostream>
using namespace std;

bool mp[4][4];
int main() {
    string s;
    int tmp = 0;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        tmp = s[i] - '0' - 1;
        mp[tmp / 3 + 1][tmp % 3 + 1] = i % 2;
    }
    /*
    for(int i = 1; i <= 3; ++i) {
        for(int j = 1; j <= 3; ++j) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
    */
    for(int i = 1; i <= 3; ++i) {
        //ºáÏò
        if(mp[i][1] == mp[i][2] && mp[i][2] == mp[i][3]) {
            if(mp[i][1]) cout << "uim wins.\n";
            else cout << "xiaoa wins.\n";
            //cout << 1 << endl;
            return 0;
        }
        //×ÝÏò
        if(mp[1][i] == mp[2][i] && mp[2][i] == mp[3][i]) {
            if(mp[1][i]) cout << "uim wins.\n";
            else cout << "xiaoa wins.\n";
            //cout << 2 << endl;
            return 0;
        }
    }
    //Ð±Ïß
    if(mp[1][1] == mp[2][2] && mp[2][2] == mp[3][3]) {
        if(mp[1][1]) cout << "uim wins.\n";
        else cout << "xiaoa wins.\n";
        //cout << 3 << endl;
        return 0;
    }
    if(mp[1][3] == mp[2][2] && mp[2][2] == mp[3][1]) {
        if(mp[1][3]) cout << "uim wins.\n";
        else cout << "xiaoa wins.\n";
        //cout << 4 << endl;
        return 0;
    }
    cout << "drew.\n";
    return 0;
}