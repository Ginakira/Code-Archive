#include <iostream>
#include <string>
using namespace std;

int main() {
    int p1, p2, p3;
    string s;
    cin >> p1 >> p2 >> p3;
    //p1 1Ìî³äÐ¡Ð´ 2Ìî³ä´óÐ´ 3Ìî³ä*
    //p2 Ìî³ä¸öÊý
    //p3 1ÕýÐò 2ÄæÐò
    cin >> s;
    string fin;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] != '-') fin += s[i];
        else if(s[i] == '-' && (i == 0 || i == s.length() - 1)) fin += s[i];
        else if(s[i] == '-' && (s[i + 1] == '-' || s[i - 1] == '-')) fin += s[i];
        else {
            if(s[i - 1] >= s[i + 1]) fin += s[i];
            else if(s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] > '9') fin += s[i];
            else {
                if(p3 == 1) {
                    for(int j = s[i - 1] + 1; j < s[i + 1]; ++j) {
                        for(int k = 0; k < p2; ++k) {
                            if(p1 == 1) fin += (char)j;
                            else if(p1 == 2) {
                                if(char(j) >= '0' && char(j) <= '9') {
                                    fin += char(j);
                                }
                                else fin += (char)(j - 32);
                            }
                            else fin += '*';
                        }
                    }
                }
                else {
                    for(int j = s[i + 1] - 1; j > s[i - 1]; --j) {
                        for(int k = 0; k < p2; ++k) {
                            if(p1 == 1) fin += (char)j;
                            else if(p1 == 2) {
                                if(char(j) >= '0' && char(j) <= '9') {
                                    fin += char(j);
                                }
                                else fin += (char)(j - 32);
                            }
                            else fin += '*';
                        }
                    }
                }
            }
        }
    }
    cout << fin << endl;
    return 0;
}