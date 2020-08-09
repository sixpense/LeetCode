/*
 * Given a set of distinct intrgers, nums, return all possible subsets(the power set).
 * Note: the Solution set must not contain duplicate subsets.
 * Example:
 * Input: nums = [1, 2, 3]
 * Output: [[3], [2], [1], [3, 2], [3, 1], [2, 1], [3, 2, 1], []]
 */

class Solution{
publc:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length = nums.size();
        if(length < 1) {
            return NULL;
        }
        vector<vector<int>> res;
        int num_size = pow(2, length);
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < num_size; j++) {
                if((1 << j) & i) {
                    res[i].push_back(num[j]);
                }
            }
        }
        return res;
    }
}
