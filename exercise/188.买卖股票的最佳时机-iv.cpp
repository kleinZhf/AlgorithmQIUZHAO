/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        if (k > n / 2) return maxProfitInf(prices);

        vector<vector<vector<int>>> dp(n, 
        vector<vector<int>>(k + 1, vector<int>(2, 0)));


        for (int j = 0; j <= k; ++j) dp[0][j][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
private:
    int maxProfitInf(vector<int>& prices) {
        int n = prices.size();

        int dp0 = 0, dp1 = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int tmp = dp0;
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, tmp - prices[i]);
        }

        return dp0;
    }
};
// @lc code=end

