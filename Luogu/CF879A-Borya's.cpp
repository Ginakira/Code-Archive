#include <iostream>
using namespace std;

struct Doctor {
    int s, d;
};

Doctor doc[2333];

int main() {
    int n;
    cin >> n;
    int day = 1;
    for(int i = 0; i < n; ++i) {
        cin >> doc[i].s >> doc[i].d;
        if(i == 0) day = doc[0].s + 1;
        else {
            while(doc[i].s < day) {
                doc[i].s += doc[i].d;
            }
            day = doc[i].s + 1;
        }
    }
    cout << day - 1 << endl;
    return 0;
}