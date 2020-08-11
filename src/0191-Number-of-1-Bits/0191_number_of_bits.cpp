/*
 * Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
 * Example:
 * Input: 0000000000000000000000000001011
 * Output: 3
 */

class Solution {
public:
    int hammingWeight(uing32_t n) {
        int number_bit = 0;
        for(int i = 0; i < 32; i++) {
            if((n << i) & 1) {
                number_bit++;
            }
        }
        return number_bit;
    }
};

class Solution_binarry {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + (n >> 1 & 0x55555555);
        n = (n & 0x33333333) + (n >> 2 & 0x33333333);
        n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
        return (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
    }
};
