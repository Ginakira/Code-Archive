#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    string s;
    int num;
};

Node p[30];

bool cmp(Node a, Node b) {
    if(a.s.length() == b.s.length()) {
        for(int i = 0; i < a.s.length(); ++i) {
            if(a.s[i] == b.s[i]) continue;
            return a.s[i] > b.s[i];
        }
    }
    return a.s.length() > b.s.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> p[i].s;
        p[i].num = i + 1;
    }
    sort(p, p + n, cmp);
    cout << p[0].num << endl << p[0].s << endl;
    return 0;
}