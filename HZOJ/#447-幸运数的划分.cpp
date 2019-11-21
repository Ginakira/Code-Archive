#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int lucky[15] = {4, 7, 44, 444, 77, 777, 47, 74, 474, 447, 744, 747, 774, 477};

int main() {
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 0; i < 14; ++i) {
        if (n % lucky[i] == 0) flag = true;
    }#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int lucky[15] = {4, 7, 44, 444, 77, 777, 47, 74, 474, 447, 744, 747, 774, 477};

int main() {
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 0; i < 14; ++i) {
        if (n % lucky[i] == 0) flag = true;
    }
    if(!flag) cout << "NO";
    else cout << "YES";
    return 0;
}
    if(!flag) cout << "NO";
    else cout << "YES";
    return 0;
}