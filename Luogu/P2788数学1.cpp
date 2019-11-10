#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<char> op;
queue<int> num;
string s;
int ans = 0, tmp_num = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    op.push('+');
    for(int i = 0; i <= s.length(); ++i) {
        if(s[i] == '+' || s[i] == '-' || i == s.length()) {
            num.push(tmp_num);
            tmp_num = 0;
            if(i != s.length()) {
                op.push(s[i]);
            }
        }
        else {
            tmp_num *= 10;
            tmp_num += s[i] - '0';
        }
    }
    while(!num.empty()) {
        if(op.front() == '+') {
            ans += num.front();
            num.pop();
            op.pop();
        }
        if(op.front() == '-') {
            ans -= num.front();
            num.pop();
            op.pop();
        }
    }
    cout << ans << endl;
    return 0;
}