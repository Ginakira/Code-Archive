#include <iostream>
using namespace std;

int sum[1000] = {0};
int main() {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for(int i = 1; i <= s1; ++i) {
        for(int j = 1; j <= s2; ++j) {
            for(int k = 1; k <= s3; ++k) {
                sum[i + j + k]++;
            }
        }
    }
    int ans = 1000, num = 0;
    for(int i = 3; i <= s1 + s2 + s3; ++i) {
        if(sum[i] == 0) continue;
        if(sum[i] > num) {
            num = sum[i];
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}