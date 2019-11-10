#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<string, int> var;

int turn(string a) {
    bool neg = false;
    int sum = 0;
    for (int i = 0; i <= a.length() - 1; ++i) {
        if(a[i] == '-') {
            neg = true;
            continue;
        }
        sum *= 10;
        sum += a[i] - '0';
    }
    if (neg) return 0 - sum;
    return sum;
}

int main() {
    //cout << turn("-12345");
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        string a, op;
        int b;
        for (int i = 0; i < n - 1; ++i) {
            cin >> a >> op >> b;
            var[a] = b;
        }
        int sum = 0;
        cin >> a >> op;
        if(a[0] == '-' || (a[0] >= '0' && a[0] <= '9')) {
            sum += turn(a);
        }
        else
            sum += var[a];
        while (op != "=") {
            cin >> a;
            if (a[0] == '-' || (a[0] >= '0' && a[0] <= '9')) {
                if (op == "+") sum += turn(a);
                else
                    sum -= turn(a);
            }
            else {
                if (op == "+") sum += var[a];
                else
                    sum -= var[a];
            }
            cin >> op;
        }
        cin >> op;
        cout << sum << endl;
    }
    return 0;
}