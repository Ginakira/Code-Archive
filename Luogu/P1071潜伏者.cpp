#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, char> mp;
int check[30]; //用于检查密码是否矛盾
int main() {
    string pass, key, msg;
    cin >> pass >> key >> msg;
    if(pass.length() < 26) {
        cout << "Failed\n";
        return 0;
    }
    for(int i = 0; i < key.length(); ++i) {
        if(mp.count(pass[i]) && mp[pass[i]] != key[i]) {
            cout << "Failed\n";
            return 0;
        }
        mp[pass[i]] = key[i];
    }
    for(int i = 'A'; i <= 'Z'; ++i) {
        if(mp.count(i) == 0) {
            cout << "Failed\n";
            return 0;
        }
    }
    map<char, char>::iterator it;
    for(it = mp.begin(); it != mp.end();) {
        map<char, char>::iterator it2;
        for(it2 = it++; it2 != mp.end(); ++it2) {
            if(it->first != it2->first && it->second == it2->second) {
                cout << "Failed\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < msg.length(); ++i) {
        cout << mp[msg[i]];
    }
    return 0;
}