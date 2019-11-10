#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<int> ex;
    int t = 0;
    for(int i = 0; str[i] != '@'; ++i) {
        if((str[i] >= '0' && str[i] <= '9') || str[i] == '.' ) {
            if(str[i] == '.') {
                ex.push(t);
                t = 0;
            }
            else {
            t *= 10;
            t += str[i] - '0';
            }
            //cout << "t: " << t << endl;
        }
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int a = ex.top();
            //cout << "a:" << a << endl;
            ex.pop();
            int b = ex.top();
            //cout << "b:" << b << endl;
            ex.pop();
            if(str[i] == '+') b += a;
            else if(str[i] == '-') b -= a;
            else if(str[i] == '*') b *= a;
            else if(str[i] == '/') b /= a;
            //cout << "sum:" << b << endl;
            ex.push(b);
        }
    }
    cout << ex.top() << endl;
    return 0;
}