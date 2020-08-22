/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> list(1001, 0);

        for (const auto & n : arr1) {
            list[n]++;
        }

        vector<int> res;
        for (const auto & n : arr2) {
            while (list[n]) {
                res.push_back(n);
                list[n]--;
            }
        }

        for (int i = 0; i <= 1000; ++i) {
            for (int j = 0; j < list[i]; ++j) {
                res.push_back(i);
            }
        }

        return res;
    }
};
// @lc code=end

