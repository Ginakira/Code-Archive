#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> recv;
map<string, int> post;
string order[20];

int main() {
    int np;
    cin >> np;
    for(int i = 0; i < np; ++i) {
        cin >> order[i];
        recv[order[i]] = 0;
        post[order[i]] = 0;
    }
    string name;
    int m, n;
    for(int i = 0; i < np; ++i) {
        cin >> name >> n >> m;
        if(n != 0 && m != 0) {
            recv[name] += n % m;
            post[name] += n;
        }
        int money;
        if(n == 0 || m == 0) money = 0;
        else money = n / m;
        string tmp;
        for(int j = 0; j < m; ++j) {
            cin >> tmp;
            recv[tmp] += money;
        }
    }
    for(int i = 0; i < np; ++i) {
        cout << order[i] << ' ' << recv[order[i]] - post[order[i]];
        cout << endl;
    }
    return 0;
}