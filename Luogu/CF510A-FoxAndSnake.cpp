#include <iostream>
#include <string>
using namespace std;

int main() {
    int row, col, cnt = 1;
    cin >> row >> col;
    for(int i = 1; i <= row; ++i) {
        if(i % 2 == 0) {
            if(cnt % 2 != 0) {
                for(int j = 1; j < col; ++j) cout << '.';
                cout << '#';
                cnt++;
            }
            else {
                cout << '#';
                for(int j = 1; j < col; ++j) cout << '.';
                cnt++;
            }
        }
        else for(int j = 1; j <= col; ++j) cout << '#';
        cout << endl;
    }
    return 0;
}