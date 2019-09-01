class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sum;
        if(nums.empty())
            return 0;
        else
            sum = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] != nums[i])
            {
                nums[sum] = nums[i];
                sum += 1;                
            }
                
        }
        return sum;
    }
};
