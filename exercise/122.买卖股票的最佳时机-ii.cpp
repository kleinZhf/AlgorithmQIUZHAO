/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, cur = prices[0];

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] >= cur) {
                res += prices[i] - cur;
            }
            cur = prices[i];
        }

        return res;
    }
};
// @lc code=end

