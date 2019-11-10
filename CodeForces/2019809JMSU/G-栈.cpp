#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Patient {
    int id;
    int level;
    bool operator < (const Patient x) const{
        if(level == x.level) {
            return id > x.id;
        }
        return level < x.level;
    }
};

Patient p;

int main() {
    int n;
    while(cin >> n) {
        p.id = 0;
        priority_queue <Patient> d[4];
        for(int j = 1; j <= n; ++j) {
            string s;
            cin >> s;
            if(s == "IN") {
                p.id++;
                int doc;
                cin >> doc;
                cin >> p.level;
                d[doc].push(p);
            }
            else {
                int out_doc;
                cin >> out_doc;
                if(!d[out_doc].empty()) {
                    cout << d[out_doc].top().id << endl;
                    d[out_doc].pop();
                }
                else cout << "EMPTY" << endl;
            }
        }
    }
    return 0;
}