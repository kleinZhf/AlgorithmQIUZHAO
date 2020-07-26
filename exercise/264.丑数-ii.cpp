/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> dp(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; ++i) {
            dp[i] = min(2*dp[i2], min(3*dp[i3], 5*dp[i5]));

            while (2 * dp[i2] <= dp[i]) ++i2;
            while (3 * dp[i3] <= dp[i]) ++i3;
            while (5 * dp[i5] <= dp[i]) ++i5;
        }

        return dp[n-1];
    }
};
// @lc code=end

