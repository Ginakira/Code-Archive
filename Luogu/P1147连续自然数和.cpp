#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    for(int i = 1; i < m; ++i) {
        int sum = 0, r = i;
        while(sum < m) {
            sum += r++;
        }
        if(sum == m) cout << i << ' ' << r - 1<< endl;
    }
    return 0;
}