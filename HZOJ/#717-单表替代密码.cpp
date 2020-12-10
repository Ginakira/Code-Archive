/************************************************************
    File Name : #717-单表替代密码.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/12/10 15:02:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    char dict[30] = {0};
    string result, password;
    getline(cin, result);
    cin >> password;
    for (int i = 0; i < 26; ++i) {
        dict[password[i] - 'a'] = 'a' + i;
    }
    for (int i = 0; i < result.length(); ++i) {
        if (result[i] == ' ') {
            cout << ' ';
        } else if (islower(result[i])) {
            cout << dict[result[i] - 'a'];
        }
    }
    cout << endl;
    return 0;
}