
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> hash(26, 0);
        string ans;
        ans.reserve(T.size());
        for(auto&e:T)
            hash[e - 'a']++;
        for(auto&e:S) {
            ans += string(hash[e - 'a'], e);
            hash[e - 'a'] = 0;
        }
        for(int i = 0; i < 26; ++i) {
            ans += string(hash[i], i+'a');
        }
        return ans;
    }
};
