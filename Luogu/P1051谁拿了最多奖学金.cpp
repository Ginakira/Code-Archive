#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int num, ave, cm, pp, money;
    char cad, west;
};

Student s[105];

bool cmp(Student a, Student b) {
    if(a.money == b.money) return a.num < b.num;
    return a.money > b.money;
}

int Cal(Student a) {
    int t = 0;
    if(a.ave > 80 && a.pp >= 1) t += 8000;
    if(a.ave > 85 && a.cm > 80) t += 4000;
    if(a.ave > 90) t += 2000;
    if(a.west == 'Y' && a.ave > 85) t += 1000;
    if(a.cm > 80 && a.cad == 'Y') t += 850;
    return t;
}

int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        s[i].num = i;
        cin >> s[i].name >> s[i].ave >> s[i].cm >> s[i].cad >> s[i].west >> s[i].pp;
        sum += s[i].money = Cal(s[i]);
    }
    sort(s, s + n, cmp);
    cout << s[0].name << '\n' << s[0].money << '\n' << sum << '\n';
    return 0;
}