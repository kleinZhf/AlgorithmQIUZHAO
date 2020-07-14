/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int inc = 1;

        for (int i = 0; i < digits.size(); ++i) {
            if (inc == 0) break;
            digits[i] += inc;
            inc = digits[i] / 10;
            digits[i] %= 10;
        }

        if (inc) digits.push_back(inc);

        reverse(digits.begin(), digits.end());

        return digits;
    }
};
// @lc code=end

