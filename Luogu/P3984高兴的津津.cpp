#include <iostream>
#include <algorithm>
using namespace std;

int ti[200001];
int main() {
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; ++i) {
        cin >> ti[i];
    }
    int day = 0;
    for(int i = 1; i < n; ++i) {
        if(ti[i] - ti[i - 1] > t) day += t;
        else day += ti[i] - ti[i - 1];
    }
    cout << day + t << endl;
    return 0;
}