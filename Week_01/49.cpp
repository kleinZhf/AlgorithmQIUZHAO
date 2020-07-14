/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> mp;
        std::vector<std::vector<std::string>> res;

        for (const auto &s : strs) {
            std::string tmp(s);
            std::sort(tmp.begin(), tmp.end());

            if (mp.count(tmp) == 0) {
                mp[tmp] = std::vector<std::string>();
            }
            mp[tmp].push_back(s);
        }

        for (const auto &it : mp) {
            res.push_back((it).second);
        }

        return res;
    }
};
// @lc code=end

