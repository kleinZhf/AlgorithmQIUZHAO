/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
private:
    void dfs(int start, vector<int>& nums, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
        }
        else {

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            dfs(start + 1, nums, res);
            swap(nums[start], nums[i]);
        }
        }
    }
};

/* class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        dfs(nums, 0, perms);
        return perms;
    }
private:
    void dfs(vector<int> nums, int i, vector<vector<int>>& perms) {
        if (i == nums.size()) {
            perms.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                dfs(nums, i + 1, perms);
            }
        }
    }
}; */
// @lc code=end

