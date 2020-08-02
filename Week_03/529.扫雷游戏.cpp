/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1]);
        return board;
    }
private:
    vector<vector<int>> direct{
        {1, 0}, {0, 1}, {-1, 0}, {0, -1},
        {1, -1}, {1, 1}, {-1, -1}, {-1, 1}
    };
    int ctBoom(vector<vector<char>>& board, int x, int y) {
        int res = 0;
        for (int i = 0; i < direct.size(); ++i) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) continue;
            res += board[nx][ny] == 'M';
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        if (board[x][y] != 'E') return;

        int ct = ctBoom(board, x, y);

        if (ct) {
            board[x][y] = '0' + ct;
        }
        else {
            board[x][y] = 'B';
            for (int i = 0; i < direct.size(); ++i) {
                int nx = x + direct[i][0];
                int ny = y + direct[i][1];
                dfs(board, nx, ny);
            }
        }
    }
};
// @lc code=end

