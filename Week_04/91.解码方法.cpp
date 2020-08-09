/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i] = i == 1 ? 1 : dp[i - 2];
                }
                else {
                    return 0;
                }
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] = dp[i - 1] + (i == 1 ? 1 : dp[i - 2]);
            }
            else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end

