#include <iostream>
#include <set>
using namespace std;

set<int> s;
int fin[233];

int main() {
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        s.insert(tmp);
    }
    //cout << s.size() << endl;
    if(s.size() < 2) {
        cout << "NO";
        return 0;
    }
    set<int>::iterator it;
    int i = 0;
    for (it = s.begin(); it != s.end(); ++it) {
        if(i >= 2)
            break;
        fin[i++] = *it;
    }
    
    cout << fin[1];
    return 0;
}