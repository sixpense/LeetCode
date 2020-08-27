/*
 * 使用回溯法
 */

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        backtrack(ret, tmp, nums, 0);
        return ret;
    }

    void backtrack(vector<vector<int> >& list, vector<int>& templist, vector<int>& nums, int start) {
        list.push_back(templist);
        for(int i = start; i < nums.size(); ++i) {
            templist.push_back(nums[i]);
            backtrack(list, templist, nums, i+1);
            templist.pop_back();
        }
    }
}
