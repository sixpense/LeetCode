class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        for(int i = 1; i <= K; ++j) {
            dp[1][j] = 0;
        }
        for(int i = 1; i <= N; ++i) {
            dp[i][1] = i;
        }
        for(int i = 2; i <= N; ++i) {
            for(int j= 2; j <= K; ++j) {
                dp[i][j] = binary_Valley(i, j, dp);
            }
        }
    }
private:
    int binary_Valley(int floors, int eggs, vector<vector<int>>& dp) {
        int l = 1;
        int r = floors;
        while(l < r) {
            int LMid = l + (r - l)/2;
            int broken = dp[LMid - 1][eggs - 1];
            int not_broken = dp[floors - LMid][eggs];
            if(not_broken > broken) {
                l = LMid + 1;
            }
            else {
                r = LMid;
            }
        }
        return max(dp[r-1][eggs - 1], dp[floors - r][eggs]) + 1;
    }
};
