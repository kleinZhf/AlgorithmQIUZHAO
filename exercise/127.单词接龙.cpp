/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
static int x = []() {
std::ios::sync_with_stdio(false);
cin.tie(NULL);
return 0; }();

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        int step = 1;

        if (words.find(endWord) == words.end()) return 0;

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        
        while (!beginSet.empty()) {
            unordered_set<string> tmpSet;
            ++step;
            for (const auto &s : beginSet) {
                words.erase(s);
            }

            for (const auto &s : beginSet) {
                for (int i = 0; i < s.size(); ++i) {
                    string tmp(s);
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (endSet.find(tmp) != endSet.end()) return step;
                        if (words.find(tmp) != words.end()) {
                            tmpSet.insert(tmp);
                        }
                    }
                }
            }

            if (tmpSet.size() < endSet.size()) {
                beginSet = tmpSet;
            }
            else {
                beginSet = endSet;
                endSet = tmpSet;
            }
        }

        return 0;
    }
};
// @lc code=end

