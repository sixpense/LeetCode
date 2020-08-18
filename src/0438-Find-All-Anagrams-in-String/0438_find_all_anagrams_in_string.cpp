/*
 * 找到字符串中所有字母异位词
 * 给定一个字符串s和一个非空字符串p, 找到s中所有是p定字母异位词定子串, 返回子串中的索引.
 * 字符串只包含小写英文字母, 并且字符串s和p 的长度都不超过20100.
 * 说明: 字母异位词指字母相同, 但排列不同的字符串; 不考虑答案输出的顺序.
 * Example 
 * Input: "cbaebabacd" p: "abc"
 * Output: [0, 6]
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int s_length = s.length(), p_length = p.length();
        if(s.length() == 0 || s_length() < p_length) {
            return nullptr;
        }
        for(int i = 0; i < s_length - p_length; i++) {
            if(inString(s[i])) {
                bool status = true;
                for(int j = 1; j < p_length; j++) {
                    if(!inString(s[i + j])) {
                        status = false;
                    }
                }
                if(status) {
                    string s_spilt = str.copy(s, i, i+j);
                    sort(s_spilt.begin(), s_spilt.end());
                    sort(p.begin(), p.end());
                    if(s_spilt.equals(p)) {
                        result.push_back(i);
                    }
                }
            }
        }
    }

    // 判断某位字符是否在另一个字符串中
    bool inString(char char_str, string string_p) {
        int p_length = string_p.length();
        for(int i = 0; i < p_length; i++) {
            if(char_str == string_p[i])
                return true;
        }
        return false;
    }
};
