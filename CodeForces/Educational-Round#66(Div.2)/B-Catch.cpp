#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> loop;

int main() {
    int n, cnt, x = 0;
    string op;
    cin >> n;
    while(n--) {
        int tmp = 0;
        cin >> op;
        if(op == "add" && loop.empty()) ++x;
        else if(op == "add" && !loop.empty()) ++tmp;
        else if(op == "for") {
            cin >> cnt;
            loop.push(cnt);
        }
        else if(op == "end") {
            
        }
    }
    return 0;
}