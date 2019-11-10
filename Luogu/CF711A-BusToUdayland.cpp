#include <iostream>
#include <string>
using namespace std;

string lef[2333], rig[2333];
int main() {
    int n;
    string tmp;
    bool emp = false;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        lef[i] = tmp.substr(0, 2);
        rig[i] = tmp.substr(3, 2);
        if(lef[i] == "OO" && !emp) emp = true, lef[i] = "++";
        else if(rig[i] == "OO" && !emp) emp = true, rig[i] = "++";
    }
    if(emp) {
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {
            cout << lef[i] << '|' << rig[i] << endl;
        }
    }
    else cout << "NO";

    return 0;
}