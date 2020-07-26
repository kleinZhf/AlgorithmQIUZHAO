/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (const auto &s : strs) {
            string tmp(s);
            sort(tmp.begin(), tmp.end());

            if (mp.find(tmp) == mp.end()) {
                mp[tmp] = vector<string>();
            }

            mp[tmp].push_back(s);
        }

        for (const auto &m : mp) {
            res.push_back(m.second);
        }

        return res;
    }
};
// @lc code=end

