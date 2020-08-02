/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> chess;
        generate(0, chess, n);
        return res;
    }
private:
    vector<vector<string>> res;
    void generate(int level, vector<int>& chess, int n) {
        if (level == n) {
            store_result(chess);
            return;
        }

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
            if (!flag) {
                chess.push_back(cur);
                generate(level + 1, chess, n);
                chess.pop_back();
            }
        }
    }

    void store_result(vector<int>& chess) {
        vector<string> sol;

        for (const auto &c : chess) {
            string tmp;
            for (int i = 0; i < chess.size(); ++i) {
                if (c & (1 << i)) {
                    tmp.push_back('Q');
                }
                else {
                    tmp.push_back('.');
                }
            }
            sol.push_back(tmp);
        }

        res.push_back(sol);
    }
};
// @lc code=end

