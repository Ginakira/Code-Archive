#include <iostream>
using namespace std;

int main() {
    int n, l, g;
    cin >> n >> l >> g;
    while(n--) {
        int w, h;
        cin >> w >> h;
        while (w > g || h > g) {
            w /= 2;
            h /= 2;
        }
        //cout << w << endl << h << endl;
        if(w < l || h < l) cout << "Too Young" << endl;
        else if(w != h) cout << "Too Simple" << endl;
        else cout << "Sometimes Naive" << endl;
    }
    return 0;
}