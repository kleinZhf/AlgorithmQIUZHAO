/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int a = nums[0], b = max(nums[0], nums[1]);
        int res1 = b;

        for (int i = 2; i < nums.size() - 1; ++i) {
            res1 = max(b, a + nums[i]);
            a = b;
            b = res1;
        }

        a = nums[1];
        b = max(nums[1], nums[2]);
        int res2 = b;
        for (int i = 3; i < nums.size(); ++i) {
            res2 = max(b, a + nums[i]);
            a = b;
            b = res2;
        }

        return max(res1, res2);
    }
};
// @lc code=end

