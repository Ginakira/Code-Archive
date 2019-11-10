#include <iostream>
#include <algorithm>
using namespace std;

struct Milk {
    int price, amount;
};

Milk milk[5050];

bool cmp(Milk a, Milk b) {
    return a.price < b.price;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> milk[i].price >> milk[i].amount;
    }
    sort(milk, milk + m, cmp);
    int cost = 0, i = 0;
    while(n != 0) {
        if(milk[i].amount > n) milk[i].amount = n;
        cost += milk[i].price * milk[i].amount;
        n -= milk[i].amount;
        ++i;
    }
    cout << cost << endl;
    return 0;
}