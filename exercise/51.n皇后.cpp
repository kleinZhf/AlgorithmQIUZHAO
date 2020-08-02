/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return {};
        vector<int> chess;
        vector<string> sol;
        generate(0, chess, sol, n);
        return res;
    }
private:
    vector<vector<string>> res;
    void generate(int level, vector<int>& chess, vector<string>& sol, int n) {
        if (level == n) {
            res.push_back(sol);
            return;
        }

        string tmp(n, '.');

        for (int i = 0; i < n; ++i) {
            int cur = 1 << i;
            int flag = 0;
            for (int j = 0; j < level; ++j) {
                if ((cur & chess[j]) ||
                ((cur << (level - j)) & chess[j]) ||
                ((cur >> (level - j)) & chess[j])) {
                    flag = 1;
                    break;
                }
            }
                if (flag) continue;

                tmp[i] = 'Q';
                chess.push_back(cur);
                sol.push_back(tmp);
                generate(level + 1, chess, sol, n);
                chess.pop_back();
                sol.pop_back();
                tmp[i] = '.';
        }
    }
};
// @lc code=end

