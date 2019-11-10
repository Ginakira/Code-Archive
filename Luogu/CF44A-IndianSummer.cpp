#include <iostream>
#include <set>
using namespace std;

set<string> leaf;

string s;
int main()
{
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        leaf.insert(s);
    }
    cout << leaf.size();
    return 0;
}