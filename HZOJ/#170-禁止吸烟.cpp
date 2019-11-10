#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string slogans[2333];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> slogans[i];
    }
    string s = "No_smoking";
    size_t pos;
    for (int i = 0; i < n; ++i) {
        pos = slogans[i].find("Ban_smoking");
        while (pos != slogans[i].npos) {
            pos = slogans[i].find("Ban_smoking");
            if (pos != slogans[i].npos) {
                slogans[i].replace(pos, 11, s);
            }
        }
        cout << slogans[i] << endl;
    }
    return 0;
}