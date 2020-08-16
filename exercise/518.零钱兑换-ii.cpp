/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (!amount) return 1;

        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int j = 0; j <= coins.size(); ++j) dp[j][0] = 1;

        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= coins.size(); ++j) {
                if (i < coins[j - 1]) {
                    dp[j][i] = dp[j - 1][i];
                }
                else {
                    dp[j][i] = dp[j - 1][i] + dp[j][i - coins[j - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};
// @lc code=end

