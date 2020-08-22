/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;

        while (true) {
            while (j < s.size() && s[j] == ' ') ++j;
            if (j == s.size()) break;

            i = j;
            while (j < s.size() && s[j] != ' ') ++j;
            reverse(s, i, j - 1);
        }

        return s;
    }

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

