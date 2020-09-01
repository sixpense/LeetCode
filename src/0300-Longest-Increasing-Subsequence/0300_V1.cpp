/*
 * 使用堆配合堆配合二分查找, 使解法的时间复杂度为O(NlogN)
 * 最长递增子序列和patience game 的纸牌游戏有关.
 */

public int lengthOfLIS(int[] nums) {
    int[] top = new int[nums.length];

    // 排堆初始化为0
    int piles = 0;
    for(int i = 0; i < nums.length; i++) {
        int poker = nums[i];

        /******* 搜索左侧边界的二分查找 *******/
        int left = 0, right = piles;
        while(left < right) {
            int mid = (left + right) / 2;
            if(top[mid] > poker) {
                right = mid;
            }
            else if (top[mid] < poker) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        // 没找到合适的牌堆, 新建一堆
        if(left == piles)
            piles++;
        top[left] = poker;
    }

    return piles;
}
