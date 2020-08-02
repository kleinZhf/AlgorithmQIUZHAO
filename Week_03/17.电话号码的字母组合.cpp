/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        list['2'] = "abc";
        list['3'] = "def";
        list['4'] = "ghi";
        list['5'] = "jkl";
        list['6'] = "mno";
        list['7'] = "pqrs";
        list['8'] = "tuv";
        list['9'] = "wxyz";

        string tmp;
        generate(0, digits, tmp);
        return res;
    }
private:
    unordered_map<char, string> list;
    vector<string> res;
    void generate(int cur, string& digits, string& tmp) {
        if (cur == digits.size()) {
            res.push_back(tmp);
            return;
        }

        string curlist(list[digits[cur]]);

        for (int i = 0; i < curlist.size(); ++i) {
            tmp.push_back(curlist[i]);
            generate(cur + 1, digits, tmp);
            tmp.pop_back();
        }

    }
};
// @lc code=end

