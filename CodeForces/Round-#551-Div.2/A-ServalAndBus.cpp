/*************************************************************************
	> File Name: A-ServalAndBus.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月13日 星期六 22时19分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct Bus{
    int number;
    int time;
    int next;
} bus1[100];

bool cmp(Bus a, Bus b) {
    return a.time < b.time;
}

int main() {
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; ++i) {
        cin >> bus1[i].time >> bus1[i].next;
        bus1[i].number = i;
    }
    for(int i = 1; i <= n; ++i) {
        while(bus1[i].time < t) {
            bus1[i].time += bus1[i].next;
        }
    }
    sort(bus1 + 1, bus1 + n + 1, cmp);
    cout << bus1[1].number << endl;
    return 0;
}
