#include <iostream>
using namespace std;
int digit[10];
void split(int n) {
    for(int i = 5; i > 0; --i) {
        digit[i] = n % 10;
        n /= 10;
    }
}

int main() {
    int k;
    bool flag = false;
    cin >> k;
    for(int i = 10000; i <= 30000; ++i) {
        split(i);
        int s1 = digit[1] * 100 + digit[2] * 10 + digit[3];
        int s2 = digit[2] * 100 + digit[3] * 10 + digit[4];
        int s3 = digit[3] * 100 + digit[4] * 10 + digit[5];
        if(s1 % k == 0 && s2 % k == 0 && s3 % k == 0) {
            cout << i << '\n';
            flag = true;
        }
    }
    if(!flag) cout << "No\n";
    return 0;
}