/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 */

// @lc code=start
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int r, c, cnt;
        cnt = 1;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                }
                else if (!grid[i][j]) {
                    ++cnt;
                }
            }
        }

        dfs(grid, r, c, cnt);

        return res;
    }
private:
    int res = 0;
    void dfs(vector<vector<int>>& grid, int x, int y, int cnt) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
            return;
        }

        if (grid[x][y] == 2) {
            res += cnt ? 0 : 1;
            return;
        }

        grid[x][y] = -1;
        dfs(grid, x - 1, y, cnt - 1);
        dfs(grid, x + 1, y, cnt - 1);
        dfs(grid, x, y - 1, cnt - 1);
        dfs(grid, x, y + 1, cnt - 1);
        grid[x][y] = 0;
    } 
};
// @lc code=end

