/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if ((nums[left] < nums[mid] && nums[mid] > target && nums[left] <= target) ||
            (nums[right] > nums[mid] && (nums[right] < target || nums[mid] > target))) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return nums[left] == target ? left : -1;
    }
};
// @lc code=end

