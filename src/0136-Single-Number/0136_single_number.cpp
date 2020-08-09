/*
 * Given a non-empty array of integers, every element appears twice except for one, Find
 * that single one.
 * Note: Your algorithm should have a linear runtime complexity.
 * Example
 * Input: [2, 2, 1]
 * Output: 1
 * Input: [4, 1, 2, 1, 2]
 * Output: 4
 */

// 异或运算的性质
// 1)满足交换律: A^B = B^A
// 2)满足结合律: (A^B)^C = A^(B^C)
// 3)0^A = A
// 4)A^A = 0

class Solution {
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        if(length < 1) {
            return -1;
        }
        int res = 0;

        for(int i = 0; i < length; i++) {
            res ^= nums[i];
        }
        return res;
    }
};
