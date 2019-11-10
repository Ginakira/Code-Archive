#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {
    stack<char> ex;
    string str;
    cin >> str;
    for(int i = 0; str[i] != '@'; ++i) {
        if(str[i] == '(') ex.push(str[i]);
        if(str[i] == ')') {
            if(ex.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            ex.pop();
        }
    }
    if(ex.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}