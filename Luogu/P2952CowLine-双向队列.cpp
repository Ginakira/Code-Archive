#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main() {
    int s;
    cin >> s;
    char op, ps;
    int num;
    int id = 1;
    for(int i = 0; i < s; ++i) {
        cin >> op >> ps;
        if(op == 'A') {
            if(ps == 'L') dq.push_front(id++);
            else dq.push_back(id++);
        }
        else {
            cin >> num;
            if(ps == 'L') dq.erase(dq.begin(), dq.begin() + num);
            else dq.erase(dq.end() - num, dq.end());
        }
    }
    deque<int>::iterator it = dq.begin();
    for(; it != dq.end(); ++it) cout << *it << endl;
    return 0;
}
