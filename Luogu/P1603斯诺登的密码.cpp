#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void tolow(string &a) {
    int len = a.length();
    for(int i = 0; i < len; ++i) {
        if(a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
    }
    return ;
}

//26 keys
string number[30] = {"zero", "one", "two", "three", "four", "five", "six" \
, "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen" \
, "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty" \
, "a", "both", "another", "first", "second", "third"};

int result[30] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 0, 21, 44, 69, \
96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};

int fin[30];

int main() {
    string s;
    int cnt = 0;
    for(int i = 0; i < 7; ++i) {
        cin >> s;
        if(s == ".") break;
        tolow(s);
        //cout << s << endl;
        for(int j = 1; j <= 26; ++j) {
            if(s == number[j]) {
                fin[cnt++] += result[j];
                break;
            }
        }
    }
    if(cnt == 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(fin, fin + cnt);
    for(int i = 0; i < cnt; ++i) {
        if(i == 0) {
            cout << fin[0];
            continue;
        }
        else {
            if(fin[i] < 10) cout << 0 << fin[i];
            else cout << fin[i];
        }
    }

    return 0;
}