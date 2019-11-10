#include <iostream>
using namespace std;

string num[30001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    int k = 0, len = num[0].length();
    for (k = 0; k <= len; ++k) {
        char base = num[0][k];
        for (int i = 0; i < n; ++i) {
            if(num[i][k] != base) {
                cout << k;
                return 0;
            }
        }
    }
        return 0;
}