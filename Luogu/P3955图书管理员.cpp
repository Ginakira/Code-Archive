#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Id {
    int id_num;
    string id_s;
};

Id id[2333];

string need[2333];
int len[2333];

bool cmp(Id a, Id b) {
    return a.id_num < b.id_num;
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        stringstream ss;
        cin >> id[i].id_num;
        ss << id[i].id_num;
        ss >> id[i].id_s;
        //cout << "%" << id[i].id_s << endl;
    }
    for(int i = 0; i < q; ++i) cin >> len[i] >> need[i];
    sort(id, id + n, cmp);
    /* for(int i = 0; i < n; ++i) {
        cout << '#' << id[i].id_s << endl;
    } */
    for(int i = 0; i < q; ++i) {
        bool solved = false;
        for(int j = 0; j < n; ++j) {
            if(len[i] > id[j].id_s.length()) continue;
            if(id[j].id_s.substr(id[j].id_s.length() - len[i], len[i]) == need[i]) {
                cout << id[j].id_s << endl;
                solved = true;
                break;
            }
        }
        if(!solved) cout << -1 << endl;
    }
    return 0;
}