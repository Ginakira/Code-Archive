#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'A')
            sum += 1;
        else if(s[i] == '1')
            sum += 10;
        else
            sum += s[i] - '0';
    }
    cout << sum;
    return 0;
}