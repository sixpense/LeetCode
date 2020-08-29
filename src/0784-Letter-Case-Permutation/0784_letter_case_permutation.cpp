
class Solution {
public:
    vecotr<string> letterCasePermutation(string S) {
        vector<string> v;
        deque<int> dq;
        v.reserve(pow(2, S.size()) );
        for(int i = 0; i < S.size(); i++) {
            if(isalpha(S[i])) {
                dq.push_front(i); // push_front 使下标全部倒序
            }
        }
        for(int i = 0; i < pow(2, dq.size()); i++) {
            string t = S;
            int n = i;
            for(int j = 0; n != 0; j++) {
                if (n & 1) {
                    int idx = dq[j];
                    t[idx] ^= 32; // 大小写对换
                }
                n >>= 1;
            }
            v.push_back(t);
        }
        return v;
    }
};
