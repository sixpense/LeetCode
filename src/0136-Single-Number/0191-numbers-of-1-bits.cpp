/*
 * Write a function that takes an unsigned integer and return the number of '1' bits it has
 * (also known the Hamming weight).
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for(int i = 0; i < 32; i++) {
            sum += (n >> i & 1);
        }
        return sum;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + (n >> 1 & 0x55555555);
        n = (n & 0x33333333) + (n >> 2 & 0x33333333);
        n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
        n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
        return 0;
    }
}
