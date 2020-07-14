/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        int n = triangle.back().size();

        vector<int> dp(n, INT_MAX);

        dp[0] = triangle[0][0];

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }

        int res = INT_MAX;
        for (const auto &d : dp) {
            res = min(res, d);
        }

        return res;
    }
};
// @lc code=end

