#include <iostream>
using namespace std;

struct Camel {
    int pos, atpos;
};

Camel cam[233];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> cam[i].pos >> cam[i].atpos;
        cam[i].atpos += cam[i].pos;
    }
    /* for(int i = 0; i < n; ++i) {
        cout << "#" << i << ' ' << cam[i].pos << ' ' << cam[i].atpos << endl;
    } */
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(cam[j].pos == cam[i].atpos && cam[j].atpos == cam[i].pos) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}