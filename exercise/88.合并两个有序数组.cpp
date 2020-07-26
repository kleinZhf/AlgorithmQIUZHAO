/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1, l1 = m - 1, l2 = n - 1;

        while (l1 >= 0 && l2 >= 0) {
            if (nums1[l1] > nums2[l2]) {
                nums1[cur--] = nums1[l1--];
            }
            else {
                nums1[cur--] = nums2[l2--];
            }
        }

        while (l2 >= 0) {
            nums1[cur--] = nums2[l2--];
        }

    }

};
// @lc code=end

