/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, ct = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (!ct) {
                res = nums[i];
                ++ct;
            }
            else {
                nums[i] == res ? ++ct : --ct;
            }
        }

        return res;
    }
};
// @lc code=end

