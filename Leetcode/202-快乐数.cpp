#include <cstring>
#include <cmath>

class Solution {
public:
    long long cal(long long x) {
        long long ans = 0;
        while(x != 0) {
            ans += pow(x % 10, 2);
            x /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        bool mark[1000];
        memset(mark, false, sizeof(mark));
        while(n != 1) {
            n = cal(n);
            if(mark[n]) return false;
            mark[n] = true;
        }
        return true;
    }
};