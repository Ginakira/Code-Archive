#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    int num, ch, ma, en;
    int total;
};

Student s[310];

bool cmp(Student a, Student b) {
    if(a.total == b.total) {
        if(a.ch == b.ch) return a.num < b.num;
        return a.ch > b.ch;
    }
    return a.total > b.total;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        s[i].num = i;
        cin >> s[i].ch >> s[i].ma >> s[i].en;
        s[i].total = s[i].ch + s[i].ma + s[i].en;
    }
    sort(s + 1, s + n + 1,cmp);
    for(int i = 1; i <= 5; ++i) {
        cout << s[i].num << ' ' << s[i].total << '\n';
    }
    return 0;
}