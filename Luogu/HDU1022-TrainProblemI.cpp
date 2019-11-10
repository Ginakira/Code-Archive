#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, io[100], j = -1;
    string a, b;
    stack<int> in, out, s;
    cin >> n;
    cin >> a >> b;
    for(int i = n - 1; i >= 0; --i) {
        in.push(a[i] - '0');
        out.push(b[i] - '0');
    }
    while(true) {
        if(in.empty() && s.top() != out.top()) break;
        if(out.empty() || s.empty()) break;
        if(!in.empty()) {
            s.push(in.top());
            io[++j] = 1;
            in.pop();
        }
        if(s.top() == out.top()) {
            io[++j] = 0;
            s.pop();
            out.pop();
        }
    }
    if(j == 2 * n) {
        cout << "Yes." << endl;
        for(int i = 0; i <= j; ++i) {
            if(io[i] == 1) cout << "in" << endl;
            if(io[i] == 0) cout << "out" << endl;
        }
    }
    else cout << "No." << endl;
    cout << "FINISH." << endl;
    return 0;
}