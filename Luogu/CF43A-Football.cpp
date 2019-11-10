#include <iostream>
using namespace std;

int main() {
    int t1 = 0, t2 = 0, n;
    string c1 = "na", c2 = "na", tmp;
    cin >> n;
    while(n--) {
        cin >> tmp;
        if(c1 == "na")
            c1 = tmp;
        else if(c1 != "na" && c2 == "na" && tmp != c1)
            c2 = tmp;
        if(tmp == c1)
            t1++;
        else
            t2++;
    }
    if(t1 > t2)
        cout << c1;
    else
        cout << c2;
    return 0;
}