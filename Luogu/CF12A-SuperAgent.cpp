#include <iostream>
using namespace std;

int mp[5][5];

int main() {
    char c;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> c;
            if(c == 'X')
                mp[i][j] = 1;
            else
                mp[i][j] = 0;
        }
    }
    bool flag = true;
    if(mp[1][1] + mp[3][3] == 1)
        flag = false;
    if(mp[1][2] + mp[3][2] == 1)
        flag = false;
    if(mp[1][3] + mp[3][1] == 1)
        flag = false;
    if(mp[2][1] + mp[2][3] == 1)
        flag = false;
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}