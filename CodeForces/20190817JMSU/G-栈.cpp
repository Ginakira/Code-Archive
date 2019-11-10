#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Message {
    string name;
    int para, lev, id;

    bool operator < (const Message &a) const {
        if (lev == a.lev) return id > a.id;
        return lev > a.lev;
    }
};

priority_queue <Message> q;

Message msg[60010];

int main() {
    string op;
    int i = 0;
    while (cin >> op) {
        if(op == "PUT") {
            cin >> msg[i].name >> msg[i].para >> msg[i].lev;
            msg[i].id = i;
            q.push(msg[i++]);
        }
        else if(op == "GET") {
            if(q.empty()) {
                cout << "EMPTY QUEUE!\n";
                continue;
            }
            else {
                cout << q.top().name << ' ' << q.top().para << endl;
                q.pop();
            }
        }
    }
    return 0;
}