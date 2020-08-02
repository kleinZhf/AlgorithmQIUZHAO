/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        int i = 0;
        int n = nums.size();

        while (i <= limit) {
            if (limit >= n - 1) return true;
            limit = max(limit, nums[i] + i++);
        }

        return false;
    }
};
// @lc code=end

