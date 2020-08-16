/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int dp0 = 0, dp1 = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int tmp = dp0;
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, tmp - prices[i] - fee);
        }

        return dp0;
    }
};
// @lc code=end

