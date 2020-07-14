/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        int ct = 0;
        for(int start = 0; ct < n; ++start)
        {
            int cur = start;
            int prev = nums[cur];
            do {
                int next = (cur + k) % n;
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                cur = next;
                ++ct;
            } while(cur != start);
        }
    }
};
// @lc code=end

