/*
 * Reverse bits of a given 32 bits unsigned integer.
 * Example
 * Input: 00000010100101000001111010011100
 * Output: 00111001011110000010100101000000
 * Explanation: The input binary string 00000010100101000001111010011100 
 * represents the unsigned integer 43261596, so return 964176192, 
 * which its binary representation is 00111001011110000010100101000000.
 */

class Solution {
public:
    uint32_t reverseBit(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++) {
            res |= (n >> i & 1) << (32 - i);
        }
        return res;
    }
};

class Solution_Devide {
public:
    uint32_t reverseBit(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
