/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2) return {};

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int i = 0;

        while (i < n - 2) {
            int left = i + 1, right = n - 1;
            int target = -nums[i];
            while (left < right) {
                int cur = nums[left] + nums[right];
                if (cur == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[++left]);
                    while (left < right && nums[right] == nums[--right]);
                }
                else if (cur > target) {
                    --right;
                }
                else {
                    ++left;
                }
            }

            while (i < n - 2 && nums[i] == nums[++i]);
        }

        return res;
    }
};
// @lc code=end

