#include <iostream>
using namespace std;

int main() {
    int one = 0, two = 0, n, tmp;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp == 1) one++;
        else two++;
    }
    if(one < two) cout << one;
    else cout << two + (one - two) / 3;
    return 0;
}