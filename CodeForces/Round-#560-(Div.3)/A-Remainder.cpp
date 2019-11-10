#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    string number;
    cin >> number;
    int cnt = 0;
    string fin;
    string tmp1(x - y - 1, '0');
    string tmp2(y, '0');
    fin += tmp1 + '1' + tmp2;
    for(int i = number.length() - x, j = 0; i < number.length(); ++i, ++j) {
        if(number[i] != fin[j]) cnt++;
    }
    cout << cnt;
    return 0;
}