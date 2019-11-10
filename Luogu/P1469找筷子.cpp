#include <iostream>
#include <algorithm>
using namespace std;

int chop[1000010];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> chop[i];
    }
    sort(chop, chop + n);
    int cnt = 1;
    int tmp = chop[0];
    for(int i = 1; i < n; ++i) {
        if(tmp == chop[i]) cnt++;
        else {
            if(cnt % 2 != 0) {
                cout << chop[i - 1] << endl;
                return 0;
            }
            cnt = 1;
            tmp = chop[i];
        }
    }
    return 0;
}