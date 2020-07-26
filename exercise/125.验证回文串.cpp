/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return true;

        int i = 0, j = n - 1;

        while (i < j) {
            while (i < j && !isValid(s[i])) ++i;
            while (i < j && !isValid(s[j])) --j;

            if (isValid(s[i++]) != isValid(s[j--])) return false;
        }

        return true;
    }
private:
    int isValid(char c) {
        if (c >= '0' && c <= '9') return '0' - c - 1;
        if (c >= 'a' && c <= 'z') return c - 'a' + 1;
        if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
        return 0;
    }
};
// @lc code=end

