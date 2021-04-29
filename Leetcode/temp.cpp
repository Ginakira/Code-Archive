#include <iostream>
#include <string>
using namespace std;

string conversion(int m, string a, int n) {
    int l = a.length(), k;
    string b = "";
    for (int i = 0; i < l;) {  //塞入数字
        k = 0;
        //求商求余
        for (int j = i; j < l; j++) {
            int t = (k * m + a[j] - '0') % n;
            a[j] = (k * m + a[j] - '0') / n + '0';
            k = t;
        }
        b += char(k + '0');
        while (a[i] == '0') i++;
    }
    reverse(b.begin(), b.end());  //反过来
    return b;
}
int main() {
    string a, b;
    while (cin >> a) {
        b = conversion(10, a, 2);
        cout << b << endl;
    }
    return 0;
}