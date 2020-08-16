/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if (!n) return false;
        return !(n&(n-1));
    }
};
// @lc code=end

