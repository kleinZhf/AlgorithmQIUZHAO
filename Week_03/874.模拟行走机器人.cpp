/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
struct myHash {
    size_t operator()(vector<int> _vec) const {
        return static_cast<size_t>(_vec[0] * 10 + _vec[1]);
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<vector<int>, myHash> obList(obstacles.begin(), obstacles.end());
        vector<vector<int>> direct{{0,1}, {1,0}, {0,-1}, {-1,0}};

        int curd = 0, curx = 0, cury = 0;
        int res = 0;

        for (int i = 0; i < commands.size(); ++i) {
            if (commands[i] == -1) {
                curd = (curd + 1) % 4;
            }
            else if (commands[i] == -2) {
                curd = (curd + 3) % 4;
            }
            else {
                for (int j = 0; j < commands[i]; ++j) {
                    int newx = curx + direct[curd][0];
                    int newy = cury + direct[curd][1];
                    if (obList.find({newx, newy}) != obList.end()) break;
                    curx = newx;
                    cury = newy;
                }
                res = max(res, curx * curx + cury * cury);
            }
        }

        return res;
    }
};
// @lc code=end

