// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// 暴力解法 从后向前寻找第一个bad版本 2740ms
// Violent solution. From the back forward looking for the first bad version.
class Solution {
   public:
    int firstBadVersion(int n) {
        int pre_version = n;
        for (int i = n - 1; i > 0; --i) {
            if (!isBadVersion(i))
                break;
            else
                pre_version = i;
        }
        return pre_version;
    }
};

// 二分法 寻找第一个1 0000011111 4ms
// Binary Search. Search for the first '1'
class Solution2 {
   public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        while (left < right) {
            // OVERFLOW: mid = (left + right) >> 1;
            mid = left + ((right - left) >> 1);
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};