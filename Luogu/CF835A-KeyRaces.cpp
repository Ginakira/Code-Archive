#include <iostream>
using namespace std;

int main() {
    int s, v1, v2, t1, t2, u1, u2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    u1 = s * v1 + 2 * t1;
    u2 = s * v2 + 2 * t2;
    if(u1 < u2)
        cout << "First";
    else if(u2 < u1)
        cout << "Second";
    else
        cout << "Friendship";
    return 0;
}