/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        int dp_pre = 0;

        for (int i = 0; i < n; ++i) {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_pre - prices[i]);
            dp_pre = tmp;
        }

        return dp_i_0;
    }
};
// @lc code=end

