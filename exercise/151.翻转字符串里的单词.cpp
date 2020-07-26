/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        //1. remove redundant blank by copy the following words forward
        //2. when locating a word, reverse it
        //3. reverse the whole sentence

        int n = s.size();
        int i = 0, j = 0, cur = 0;
        int wordCt = 0;

        while (j < n) {
            while (i < n && s[i] == ' ') ++i;
            if (i == n) break;
            if (wordCt) s[j++] = ' ';
            cur = j;

            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverseWord(s, cur, j - 1);
            ++wordCt;

        }

        s.resize(j);
        reverseWord(s, 0, j - 1);

        return s;
    }
private:
    void reverseWord(string &s, int i, int j) {
        while (i < j) {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }
};
// @lc code=end

