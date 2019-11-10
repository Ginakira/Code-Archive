#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <cmath>
using namespace std;

string b1, b2;
stringstream ss;
long long ans = 0;

void cal() {
    int cnt = 31;
    for(int i = 0; i < b2.length(); ++i) {
        if(b2[i] == '1') ans += pow(2, cnt);
        cnt--;
    }
}

int main() {
    long long a;
    cin >> a;
    ss << bitset<32>(a);
    ss >> b1;
    b2 += b1.substr(16, 16);
    b2 += b1.substr(0, 16);
    cal();
    cout << ans << endl;
    return 0;
}