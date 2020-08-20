/* 
 * 给定一个字符串, 请你找出其中不含有重复字符的最长子串的长度.
 * Example
 * Input: "abcabcbb"
 * Outpue: 3
 * Input: "bbbbbbb"
 * OUtput: 1
 */

class Solution {
public:
    int lenghtOfLengestSubstring(string s) {
        int res = 0;
        int left = 0, right = 0;
        unordered_map<char, int> window;

        while(right < s.size()) {
            char c1 = s[right];
            window[c1]++;
            right++;

            while(window[c1] > 1) {
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
