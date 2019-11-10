#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string s;
    cin >> s;
    regex rst(".*h.*e.*l.*l.*o.*");
    if(regex_search(s, rst))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}