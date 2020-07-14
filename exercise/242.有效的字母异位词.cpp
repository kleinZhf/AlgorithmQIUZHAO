/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;

        for (const auto &c : s) {
            mp[c]++;
        }

        for (const auto &c : t) {
            if (mp.count(c) == 0) {
                return false;
            }
            else if(mp[c] == 1) {
                mp.erase(c);
            }
            else {
                mp[c]--;
            }
        }

        return mp.size() == 0;
    }
};
// @lc code=end

