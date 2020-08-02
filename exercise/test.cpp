#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>


using namespace std;

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
        cout << x << ' ' << y << ' ' << board[x][y] << endl;
        if (board[x][y] != 'E') return;

        int ct = ctBoom(board, x, y);
        cout << ct << endl;
        if (ct) {
            board[x][y] = '0' + ct;
            return;
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

int main(void) {
    vector<vector<char>> grid{
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click{3, 0};

    vector<vector<char>> res = Solution().updateBoard(grid, click);

    for (const auto& r : res) {
        for (const auto& s : r) {
            cout << s << ' ';
        }
        cout << endl;
    }

    return 0;
}
