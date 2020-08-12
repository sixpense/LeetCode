/*
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 * Example: 
 * Given num = 16, return true. Given num = 5, return false. 
 * Follow up: Could you solve it without loops/recursion?
 */

class Solution {
public:
    bool PowerOfFour(int num) {
        if(num < 0)
            return false;
        if((num & (num - 1)))       // 先判断是否是2的N次方
            return false;
        if(num & 0x55555555)        // 再将不是4的N次方去掉
            return true;
        return false;
    }
}

