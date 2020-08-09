/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        int n = s.size();

        vector<int> dp(n, 0);
        int res = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                    res = max(dp[i], res);
                }
                else if(i >= dp[i - 1] + 1 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                    res = max(dp[i], res);
                }
            }
        }

        return res;
    }
};
// @lc code=end

