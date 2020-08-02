/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

struct cmp {
    bool operator() (pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    }
};

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (const auto &m : mp) {
            pq.push(make_pair(m.second, m.first));
        }

        vector<int> res;

        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
// @lc code=end

