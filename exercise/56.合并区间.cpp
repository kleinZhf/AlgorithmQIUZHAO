/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), cmp);

        int begin = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                res.push_back({begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }

        res.push_back({begin, end});

        return res;
    }
};
// @lc code=end

