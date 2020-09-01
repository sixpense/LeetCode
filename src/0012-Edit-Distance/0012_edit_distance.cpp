/*
 * 编辑距离(Edit Distance)
 * 给定两个单词word1 和 word2, 请你计算出word1转换成word2所使用的最少操作数.
 * 你对一个单词可以进行如下操作:
 * 1. 插入一个字符
 * 2. 删除一个字符
 * 3. 替换一个字符
 * 示例1
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 示例2
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 */

/*
 * 解题思路:
 * 编辑距离问题就是给定两个字符串s1和s2, 只能用三种操作, 把s1变成s2, 求最少的操作数.
 * 前面的最长公共子序列说过, 解决连个字符串的动态规划问题, 一般用两个指针分别指向两个字符串
 * 的最后, 再一步一步网前走, 缩小问题的规模.
 */

```
python
```
def minDistance(s1, s2) -> int:
     // i, j 初始化最后一个索引
    return dp(len(s1) - 1, len(s2) - 1); 
def dp(i, j):
    if(i == -1): return j + 1;
    if(j == -1): return i + 1;

    if s1[i] == s2[j]: return dp(i - 1, j - 1);
    else:
        return min(dp(i, j - 1) + 1, dp(i - 1, j) + 1, dp(i - 1, j - 1) + 1);

// 动态规划的优化方法
// 备忘录和DP table
// DP table 是自底向上求解, 递归解法是自顶向下求解:

// Java 解法代码
    int minDistance(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[][] dp = new int[m + 1][n + 1];
        // base case 
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;
        // 自底向上求解
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
    int min(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }

// C++ 解法代码
class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1, vector<int>(n + 1));
        // base case: 当s2为空, s1需要删除所有的字符才能与s2相等
        for(int i = 1; i <= m; i++){
            dp[i][0] = i;
        }

        // base case: 当s1为空, s2需要插入新字符才能与s1相等
        for(int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
                }
            }
        }
        return dp[m][n];
    }
};
