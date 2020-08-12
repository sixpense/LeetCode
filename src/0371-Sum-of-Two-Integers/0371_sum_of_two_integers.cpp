/*
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 * Input: a = -2, b = 3
 * Output: 1
 */

class Solution {
    int GetNum(int a, int b) {
        int p, q, c = 0, ans = 0;
        for(int i = 0; i < 32; i++) {
            p = a >> i & 1;
            q = b >> i & 1;
            ans += (q ^ p ^ c) << i;
            c = (q ^ p) | (q ^ c) | (p ^ c);
        }
        return ans;
    }
};
