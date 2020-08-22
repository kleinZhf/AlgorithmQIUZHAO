/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (!n) return 0;
        long long left = 0, right = 0;

        for (int i = 0; i < n; ++i) {
            right += nums[i];
            left = left < nums[i] ? nums[i] : left;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(nums, n, mid, m)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
private:
    bool valid(vector<int>& nums, int n, long long target, int k) {
        long long cur = nums[0];
        if (cur > target) return false;
        int i = 1;

        while (i < n) {
            if (cur + nums[i] <= target) {
                cur += nums[i++];
            }
            else {
                cur = nums[i++];
                --k;
            }
        }

        return k > 0;
    }
};
// @lc code=end

