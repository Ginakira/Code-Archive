#include <iostream>
#include <string>
using namespace std;

int num[233];
int main() {
    int n;
    cin >> n;
    string final;
    int sum = 0;
    for(int i = 1; sum < n * n; ++i) {
        cin >> num[i];
        sum += num[i];
        if(i % 2 == 1) {
            string tmp(num[i], '0');
            final += tmp;
        }
        else {
            string tmp(num[i], '1');
            final += tmp;
        }
    }
    for(int i = 1; i <= n * n; ++i) {
        cout << final[i - 1];
        if(i % n == 0) cout << endl;
    }
    return 0;
}