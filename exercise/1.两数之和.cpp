/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            if (mp.count(tmp)) {
                return {i, mp[tmp]};
            }
            else {
                mp[nums[i]] = i;
            }
        }

        return {};

    }
};
// @lc code=end

