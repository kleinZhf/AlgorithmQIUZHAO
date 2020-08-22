/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;

        while (i < s.size()) {
            if (i + k - 1 < s.size()) {
                reverse(s, i, i + k - 1);
                if (i + 2 * k < s.size()) {
                    i = i + 2 * k;
                }
                else {
                    i = s.size();
                }
            }
            else {
                reverse(s, i, s.size() - 1);
                i = s.size();
            }
        }

        return s;
    }
private:
    void reverse(string &s, int begin, int end) {
        if (begin >= end) return;

        while (begin < end) {
            char c = s[begin];
            s[begin++] = s[end];
            s[end--] = c;
        }
    }
};
// @lc code=end

