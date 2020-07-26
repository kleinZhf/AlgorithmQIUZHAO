/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n <= 1) return 0;

        int left = 0, right = n - 1;
        int res = 0;

        while (left <= right) {
            if (height[left] < height[right]) {
                res = max((right - left) * height[left++], res);
            }
            else {
                res = max((right - left) * height[right--], res);
            }
        }

        return res;
    }
};
// @lc code=end

