/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int halfLen = (m + n + 1) / 2;

        while (left < right) {
            int i = left + (right - left) / 2;
            int j = halfLen - i;
            if (nums2[j - 1] > nums1[i]) {
                left = i + 1;
            }
            else {
                right = i;
            }
        }

        int i = left;
        int j = halfLen - i;

        int nums1LeftMax = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums1RightMin = (i == m ? INT_MAX : nums1[i]);
        int nums2LeftMax = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums2RightMin = (j == n ? INT_MAX : nums2[j]);

        if ((m + n) % 2 == 1) {
            return max(nums1LeftMax, nums2LeftMax);
        }
        else {
            return (double) (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
        }
    }
};
// @lc code=end

