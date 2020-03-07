// 不使用+、-号计算两整数之和

// 位运算
// 异或运算 与二进制加法得出结果一致
// 与运算 得到产生进位的位置 左移一位即为相应的进位操作
// 两个结果再进行加运算 直到进位是0为止
class Solution {
   public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, ((unsigned int)a & b) << 1);
    }
};