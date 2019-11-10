#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0, need = 1;
    int i = 0;
    while(n >= need) {
        sum += need;
        n -= need;
        i++;
        need += i + 1;
    }
    cout << i << endl;
    return 0;
}
