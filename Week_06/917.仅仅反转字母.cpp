/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int begin = 0, end = S.size() - 1;

        while (begin < end) {
            while (begin < end && !isLetter(S[begin])) ++begin;
            while (begin < end && !isLetter(S[end])) --end;
            char c = S[begin];
            S[begin++] = S[end];
            S[end--] = c;
        }
        
        return S;
    }

    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};
// @lc code=end

