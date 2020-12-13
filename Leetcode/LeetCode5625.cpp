// LeetCode 5625 字节跳动 第219场周赛 比赛中的配对次数

// 普通做法
class Solution1 {
   public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while (n > 1) {
            if (n % 2) {
                cnt += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            } else {
                cnt += n / 2;
                n /= 2;
            }
        }
        return cnt;
    }
};

// 看破红尘
// 实际上每次配对都会淘汰一支队伍，所以一定会进行n - 1次配对，最后剩下1支队伍
class Solution2 {
   public:
    int numberOfMatches(int n) { return n - 1; }
};