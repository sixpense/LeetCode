/*
 * 鸡蛋掉落(Super egg drop)
 * 你将获得K个鸡蛋, 并可以使用一栋从1到N共有N层的建筑.
 * 每个蛋的功能都是一样的, 如果一个蛋碎了, 你就不能再把它掉下去.
 * 如果存在楼层F, 满足 0 <= F <= N 任何从高于F的楼层落下的鸡蛋都会碎, 从F楼或者比它低的楼层
 * 落下的鸡蛋都不会破.
 * 无论F的初始值如何, 确定F的值的最小移动次数是多少?
 *
 * 示例1
 * 输入：K = 1, N = 2
 * 输出：2
 * 解释：
 * 鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
 * 否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
 * 如果它没碎，那么我们肯定知道 F = 2 。
 * 因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
 * 
 * 示例2
 * 输入：K = 2, N = 6
 * 输出：3
 * 
 * 示例3
 * 输入：K = 3, N = 14
 * 输出：4
 * 
 */

class Solution {
    def superEggDrop(int K, int N) {

    }
}



// python3代码
def superEggDrop(K: int, N: int):
    memo = dict()
    def dp(K, N) -> int:
        // base case
        if K == 1: return N;
        if N == 0: return 0;

        if (K, N) in memo:
            return memo[(K, N)];

        res = float('INF')
        // 穷举所有的可能的选择
        for i in range(1, N + 1):
            res = min(res, max(dp(K, N - i), dp(K - 1, i - 1)) + 1)
        memo[(K, N)] = res;
        return res;
    return dp(K, N)
