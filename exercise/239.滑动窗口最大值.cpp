/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {};

        deque<int> dq;

        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int> res;
        res.push_back(nums[dq.front()]);

        for (int j = k; j < n; ++j) {
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            while (!dq.empty() && dq.front() <= j - k) {
                dq.pop_front();
            }
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
// @lc code=end

