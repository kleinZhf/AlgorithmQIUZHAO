/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        for (int row = 0; row < matrix.size(); ++row) {
            int cur = 0;
            for (int col = 0; col < matrix[0].size(); ++col) {
                cur += matrix[row][col];
                matrix[row][col] = cur;
            }
        }

        int res = INT_MIN;
        for (int lcol = 0; lcol < matrix[0].size(); ++lcol) {
            for (int rcol = lcol; rcol < matrix[0].size(); ++rcol) {
                set<int> st;
                st.insert(0);

                int rowPrefSum = 0;
                for (int row = 0; row < matrix.size(); ++row) {
                    int curSum = matrix[row][rcol] - (lcol == 0 ? 0 : matrix[row][lcol - 1]);
                    rowPrefSum += curSum;

                    auto searchRes = st.lower_bound(rowPrefSum - k);

                    if (searchRes != st.end()) {
                        res = max(res, rowPrefSum - *searchRes);
                    }

                    st.insert(rowPrefSum);
                }
            }

        }
        return res;
    }
};
// @lc code=end

