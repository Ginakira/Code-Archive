#include <iostream>
using namespace std;

int convert(string s) {
    int sum = 0;
    for(int i = 0; i < s.size(); ++i) {
        sum *= 10;
        sum += s[i] - '0';
    }
    return sum;
}

int dig(int a) {
    if(a == 0) {
        return 1;
    }
    int sum = 0;
    while(a != 0) {
        a /= 10;
        sum++;
    }
    return sum;
}

int main() {
    int t;
    char op;
    string tmp;
    cin >> t;
    while(t--) {
        cin >> tmp;
        int a, b;
        if(tmp[0] >= 'a' && tmp[0] <= 'c') {
            cin >> a >> b;
            op = tmp[0];
        }
        else {
            a = convert(tmp);
            cin >> b;
        }
        int sum = 0;
        if(op == 'a') {
            sum = a + b;
            cout << a << '+' << b << '=' << sum << endl;
        }
        else if(op == 'b') {
            sum = a - b;
            cout << a << '-' << b << '=' << sum << endl;
        }
        else if(op == 'c') {
            sum = a * b;
            cout << a << '*' << b << '=' << sum << endl;
        }
        if(sum >= 0)
            cout << dig(a) + dig(b) + dig(sum) + 2 << endl;
        else
            cout << dig(a) + dig(b) + dig(sum) + 3 << endl;
    }
    return 0;
}