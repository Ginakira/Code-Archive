#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.find('F', s.find('C', 0)) != string::npos) {
        cout << "Yes";
    }
    else
        cout << "No";
    return 0;
}