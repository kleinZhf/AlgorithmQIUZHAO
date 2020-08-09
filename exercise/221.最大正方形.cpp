/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int m = matrix.size(), n = matrix[0].size();
        int res = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + (j == 0 ? 0 :dp[i][j - 1]);
                    int k = i, minwid = dp[i][j];
                    while (k >= 0 && minwid) {
                        minwid = min(minwid, dp[k][j]);
                        res = max(res, min(i - k-- + 1, minwid));
                    }
                }
            }
        }

        return res * res;
    }
};
// @lc code=end

