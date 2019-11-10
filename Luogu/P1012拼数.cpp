#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string num[30];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> num[i];
    sort(num, num + n, cmp);
    for(int i = 0; i < n; ++i) cout << num[i];
    cout << endl;
    return 0;
}