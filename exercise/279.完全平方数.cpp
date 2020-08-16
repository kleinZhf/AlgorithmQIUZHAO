/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int res = 0;
        queue<int> q;
        q.push(n);
        vector<int> visited(n, 0);

        while (visited[0] == 0) {
            ++res;
            int k = q.size();
            while (k--) {
                int cur = q.front();
                q.pop();
                for (int i = 1; cur - i * i >= 0; ++i) {
                    int tmp = cur - i * i;
                    if (tmp == 0) return res;
                    if (!visited[tmp]) {
                        visited[tmp] = 1;
                        q.push(tmp);
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

