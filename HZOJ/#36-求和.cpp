#include <iostream>
using namespace std;
int main() {
    int n, num, sum = 0;
    cin >> n;
    while (n--) {
        cin >> num;
        sum += num;
    }
    cout << sum << endl;
    return 0;
}