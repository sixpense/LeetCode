/*
 * There are n bulbs that are initially off. You first turn on all the bulbs.
 * Then, you turn off every second bulb. 
 * On the third round, you toggle every third bulb(turning on if it's off or turning off 
 * if it's on). For the ith round, you toggle every i bulb, for the nth round, you only
 * toggle the last bulb. Find how many bulbs are on after n rounds.
 *
 * Example:

 * Given n = 3. 
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off].
 * So you should return 1, because there is only one bulb is on.
 */


// 第i轮开关灯涉及的开关号报考 i * k 个
// 开关拨动次数为偶数, 灯泡灭
// 开关拨动次数为奇数, 灯泡亮
//
// 1 的因素有 1
// 2 的因素有 1, 2
// 3 的因素有 1, 3
// 4 的因素有 1, 2, 4
// 5 的因素有 1, 5
// 6 的因素有 1, 2, 3, 6
//
// a = b * c
//
// 当且仅当b 和 c 相等时, 因素只记录一个, 这就是出现因素为奇数的情况
// 故问题变成, 小于等于n 一共有多少平方数.

class Solution {
public:
    int bulbSwitch(int n) {
        int result = 0;
        for(int i = 1; i * i <= n; ++i) {
            ++result;
        }
        return result;
    }
};


