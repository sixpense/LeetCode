
#include <algorithm>

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int maxValue = 0;
        int ll = 0;
        int rr = 0;
        int zero = 0;
        while(rr < A.size()) {
            if(A[rr] == 0) {
                zero++;
            }
            while(zero > K) {
                if(A[ll++] == 0) {
                    zero--;
                }
            }
            maxValue = max(maxValue, rr - ll + 1);
            rr++;
        }
        return maxValue;

    }
};
