/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * Example
 * Input: [3, 2, 3]
 * Output: [3]
 * Input: [2, 2, 1, 1, 1, 2, 2]
 * Outpug: [2]
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       if(nums.size() < 0) {
            return -1;
        }
        int numbers = nums[0];
        int count = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(numbers == nums[i]) {
                count ++;
            }
            else {
                count--;
            }
            if(count < 1) {
                numbers = nums[i];
                count = 1;
            }
        }
        return numbers;  
    }
};

class Solution_Bit_Manipulation {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        for(int i = 0 i < 32; i++) {
            int ones = 0;
            int zeros = 0;

            for(num : nums) {
                if(ones > n/2 || zeros > n/2) {
                    break;
                }
                if((num & (1 << i)) != 0) {
                    ones++;
                }
                else {
                    zeros++;
                }
                if(ones > zeros) {
                    res |= (1 << i);
                }
            }
        }
        return res;
    }
};
