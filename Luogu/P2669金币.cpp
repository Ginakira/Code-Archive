#include <iostream>
using namespace std;

int main() {
    int k;
    long long coin = 0;
    cin >> k;
    for(int i = 1; k > 0; ++i) {
        if(k < i) coin += i * k;
        else coin += i * i;
        //cout << i << ' ' << coin << endl;
        k -= i;
    }
    cout << coin << '\n';
    return 0;
}