#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int num[1010], diff[1010];
int main() {
    int n, j = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
        if(i != 0) {
            diff[j++] = abs(num[i] - num[i - 1]);
        }
    }
    sort(diff, diff + j);
    for(int i = 0; i < j; ++i) {
        if(diff[i] != i + 1) {
            cout << "Not jolly\n";
            return 0;
        }
    }
    cout << "Jolly\n";
    return 0;
}