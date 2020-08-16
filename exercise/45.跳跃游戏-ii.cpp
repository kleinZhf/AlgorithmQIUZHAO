/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int n = nums.size();

        int maxlen = nums[0];
        int next_max = nums[0];
        int cnt = 1;

        for (int i = 0; i < n; ++i) {
            if (i > maxlen) {
                ++cnt;
                maxlen = next_max;
            }

            next_max = max(next_max, i + nums[i]);
        }

        return cnt;

    }
};
// @lc code=end

