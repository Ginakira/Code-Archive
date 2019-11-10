#include <iostream>
using namespace std;

int n, goal[8], win[8];
int main() {
    cin >> n;
    cin >> goal[0] >> goal[1] >> goal[2] >> goal[3] >> goal[4] >> goal[5] >> goal[6];
    for(int i = 0; i < n; ++i) {
        int tmp = 0;
        int cnt = 0;
        for(int i = 0; i < 7; ++i) {
            cin >> tmp;
            for(int j = 0; j < 7; ++j) {
                if(tmp == goal[j]) cnt++;
            }
        }
        win[cnt]++;
    }
    cout << win[7] << ' ' << win[6] << ' ' << win[5] << ' ' << win[4] << ' ' << win[3] << ' ' << win[2] << ' ' << win[1] << endl;
    return 0;
}