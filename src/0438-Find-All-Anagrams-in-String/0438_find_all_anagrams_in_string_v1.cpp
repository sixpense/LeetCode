
vector<int> findAnagrams(string s, string t) {
    vector<int> res;
    int left = 0, right = 0;
    unordered_map<char, int> needs;
    unordered_map<char, int> window;
    for(char c: t) needs[c]++;
    int match = 0;

    whild(right < s.size()) {
        char c1 = s[right];
        if(needs.count(c1)) {
            window[c1]++;
            if(window[c1] == needs[c1])
                match++;
        }
        ritht++;

        while(match == needs.size()) {
            // 如果window大小合适
            // 就把索引left加入结果
            if(right - letf == t.size()) {
                res.push_back(left);
            }
            char c2 = s[left];
            if(needs.count(c2)) {
                window[c2]--;
                if(window[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }
    return res;
}
