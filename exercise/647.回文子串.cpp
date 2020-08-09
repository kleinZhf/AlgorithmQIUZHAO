/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = n;

        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (s[j] == s[j + i]) {
                    if (i == 1) {
                        res += 1;
                        dp[j][j + 1] = 1;
                    }
                    else if (dp[j + 1][j + i - 1]) {
                        res += 1;
                        dp[j][j + i] = 1;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

