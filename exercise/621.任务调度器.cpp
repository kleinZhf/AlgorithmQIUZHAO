/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> times(26, 0);
        int len = tasks.size();

        for (int i = 0; i < tasks.size(); ++i) {
            times[tasks[i] - 'A'] += 1;
        }

        sort(times.begin(), times.end(), std::greater());

        int cnt = 1;
        while (cnt < times.size() && times[cnt] == times[0]) ++cnt;
        return max(len, cnt + (n + 1) * (times[0] - 1));
    }
};
// @lc code=end

