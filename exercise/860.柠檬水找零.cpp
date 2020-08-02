/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0;

        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                ++c5;
            }
            else if (!c5) {
                return false;
            }
            else if (bills[i] == 10) {
                ++c10;
                --c5;
            }
            else if (c10) {
                --c10;
                --c5;
            }
            else {
                c5 -= 3;
                if (c5 < 0) return false;
            }
        }

        return true;
    }
};
// @lc code=end

