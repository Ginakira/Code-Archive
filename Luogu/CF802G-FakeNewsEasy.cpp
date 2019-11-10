#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s.length() <= 5) {
        cout << "NO";
        return 0;
    }
    size_t pos;
    pos = s.find('h', 0);
    pos = s.find('e', pos);
    pos = s.find('i', pos);
    pos = s.find('d', pos);
    pos = s.find('i', pos);
    if(pos == string::npos)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}