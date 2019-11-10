#include <iostream>
#include <queue>
using namespace std;

queue<string> mt;

string mts[12] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};

int main() {
    int k;
    string s;
    cin >> s >> k;
    for (int i = 0; i < 12; ++i) {
        mt.push(mts[i]);
    }
    while(mt.front() != s) {
        mt.push(mt.front());
        mt.pop();
    }
    while(k--) {
        mt.push(mt.front());
        mt.pop();
    }
    cout << mt.front();
    return 0;
}