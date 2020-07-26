/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> path;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()) return {};

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};

        int findEnd = 0, flag = 0;

        while (!beginSet.empty()) {
            unordered_set<string> tmpSet;
            for (const auto &s : beginSet) {
                wordDict.erase(s);
            }
            for (const auto &s : beginSet) {
                for (int i = 0; i < s.size(); ++i) {
                    string tmp(s);
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (wordDict.find(tmp) == wordDict.end()) continue;

                        if (endSet.find(tmp) != endSet.end()) {
                            findEnd = 1;
                        }
                        else {
                            tmpSet.insert(tmp);
                        }

                        if (flag) {
                            path[tmp].push_back(s);
                        }
                        else {
                            path[s].push_back(tmp);
                        }
                    }
                }
            }

            if (tmpSet.size() < endSet.size()) {
                beginSet = tmpSet;
            }
            else {
                flag ^= 1;
                beginSet = endSet;
                endSet = tmpSet;
            }

            if (findEnd) break;
        }

        vector<string> tmp{beginWord};
        dfs(beginWord, endWord, tmp);
        return res;
    }

    void dfs(string begin, string end, vector<string> &tmp) {
        if (begin == end) {
            res.push_back(tmp);
            return;
        }

        for (const auto &s : path[begin]) {
            tmp.push_back(s);
            dfs(s, end, tmp);
            tmp.pop_back();
        }
    }
};
// @lc code=end

