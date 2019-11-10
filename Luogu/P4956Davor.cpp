#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    //Ã¿ÐÇÆÚ³ï¼¯7x+21k
    n /= 52;
    int x, k;
    for(int i = n / 7; i > 0; --i) {
        int k = n - 7 * i;
        if(k % 21 == 0 && k / 21 > 0 && i <= 100) {
            cout << i << endl << k / 21 << endl;
            return 0;
        }
    }
    return 0;
}