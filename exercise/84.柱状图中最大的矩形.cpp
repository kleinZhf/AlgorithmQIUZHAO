/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int n = heights.size();
        int res = 0;
        
        stack<int> S;

        for (int i = 0; i < n; ++i) {
            while (!S.empty() && heights[S.top()] > heights[i]) {
                int tmp = S.top();
                S.pop();
                res = max(res, (i - S.top() - 1) * heights[tmp]);
            }
            S.push(i);
        }

        return res;
    }
};
// @lc code=end

