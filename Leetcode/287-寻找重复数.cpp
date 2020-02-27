// 快慢指针思想 变形的链表判断环
int findDuplicate(int* nums, int numsSize) {
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);
    q = nums[0];
    while (p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}

int findDuplicate2(int* nums, int numsSize) {
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);
    int cnt = 0;
    do {
        cnt++;
        p = nums[p];
    } while (p != q);
    p = nums[0], q = nums[0];
    while (cnt--) q = nums[q];
    while (p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}