/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a1 = 1, a2 = 1, a3 = 0;

        for (int i = 2; i <= n; ++i) {
            a3 = a1 + a2;
            a1 = a2;
            a2 = a3;
        }

        return a3;
    }
};
// @lc code=end

