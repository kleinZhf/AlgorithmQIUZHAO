/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        vector<int> res;

        for (const auto &n : nums1) {
            mp[n]++;
        }

        for (const auto &n : nums2) {
            if (mp[n]) {
                res.push_back(n);
                mp[n]--;
            }
        }

        return res;
    }
};
// @lc code=end

