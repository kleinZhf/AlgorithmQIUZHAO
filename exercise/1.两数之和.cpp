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
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            if (mp.count(target - nums[i])) {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            else {
                mp[nums[i]] = i;
            }
        }

        return res;

    }
};
// @lc code=end

