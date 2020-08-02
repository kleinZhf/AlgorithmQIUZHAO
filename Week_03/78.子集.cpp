/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int all_set = 1 << nums.size();

        for (int i = 0; i < all_set; ++i) {
            vector<int> tmp;
            for (int j = 0; j < nums.size(); ++j) {
                if (i & (1 << j)) {
                    tmp.push_back(nums[j]);
                }
            }
            res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

