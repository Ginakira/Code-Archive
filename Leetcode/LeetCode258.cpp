// LeetCode 258 各位相加

class Solution {
   public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};

class Solution2 {
   public:
    int addDigits(int num) {
        return num < 10 ? num : addDigits(addDigits(num / 10) + num % 10);
    }
};