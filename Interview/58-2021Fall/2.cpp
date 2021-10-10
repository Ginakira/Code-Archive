#include <algorithm>
#include <iostream>
using namespace std;

// AC
int calculateExtraNum(int totalNum, int exchangeNum) {
    int remain = totalNum;
    int extra = 0;
    while (remain >= exchangeNum) {
        int temp = remain / exchangeNum;
        extra += temp;
        remain %= exchangeNum;
        remain += temp;
    }
    return extra;
}
int main() {
    cout << calculateExtraNum(20, 4) << endl;
    cout << calculateExtraNum(30, 3) << endl;
    cout << calculateExtraNum(31, 3) << endl;
    return 0;
}