#include <iostream>
using namespace std;

struct matrix{
    int a, b;
};

matrix ma[51][51];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> ma[i][j].a;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> ma[i][j].b;
            if(ma[i][j].b < ma[i][j].a) swap(ma[i][j].a, ma[i][j].b);
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i + 1 < n) {
                if(ma[i][j].a >= ma[i + 1][j].a) {
                    cout << "Impossible\n";
                    return 0;
                }
                if(ma[i][j].b >= ma[i + 1][j].b) {
                    cout << "Impossible\n";
                    return 0;
                }
            }
            if(j + 1 < m) {
                if(ma[i][j].a >= ma[i][j + 1].a) {
                    cout << "Impossible\n";
                    return 0;
                }
                if(ma[i][j].b >= ma[i][j + 1].b) {
                    cout << "Impossible\n";
                    return 0;
                }
            }
        }
    }
    cout << "Possible\n";
    return 0;
}