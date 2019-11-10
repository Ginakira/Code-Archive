#include <iostream>
using namespace std;

char m[5][5] = {0};
int main() {
    int cnt = 0;
    for(int i = 1; i <= 3; ++i) {
        for(int j = 1; j <= 3; ++j) {
            cin >> m[i][j];
            if(m[i][j] != '-') cnt++;
        }
    }
    if(cnt == 1 || cnt == 0) {
        cout << "Dont know.\n" << cnt << endl;
        return 0;
    }
    if(m[1][2] == 'X' || m[2][1] == 'X' || m[2][3] == 'X'  || m[3][2] == 'X' ) {
        cout << "xiaoa will win.\n" << cnt << endl;
    }
    else cout << "Dont know.\n" << cnt << endl;
    return 0;
}