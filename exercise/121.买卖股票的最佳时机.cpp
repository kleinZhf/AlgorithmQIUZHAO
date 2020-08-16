/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int minp = prices[0];
        int res = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= minp) {
                res = max(res, prices[i] - minp);
            }
            minp = min(minp, prices[i]);
        }

        return res;
    }
};
// @lc code=end

