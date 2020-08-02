/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> b(k, 0);
        int i = 0;

        while (i >= 0) {
            b[i]++;
            if (b[i] > n) {
                --i;
            }
            else if (i == k - 1) {
                res.push_back(b);
            }
            else {
                ++i;
                b[i] = b[i - 1];
            }
        }

        return res;
    }
};
// @lc code=end

