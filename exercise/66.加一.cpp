/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int inc = 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (!inc) break;
            digits[i] += inc;
            inc = digits[i] / 10;
            digits[i] %= 10;
        }

        if (inc) digits.insert(digits.begin(), inc);

        return digits;
    }
};
// @lc code=end

