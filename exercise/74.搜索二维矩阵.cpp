/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int up = 0;
        int down = row - 1;
        while (up < down) {
            int mid = up + (down - up) / 2;
            if (matrix[mid][col - 1] < target) {
                up = mid + 1;
            }
            else {
                down = mid;
            }
        }

        int left = 0;
        int right = col - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[up][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (matrix[up][left] == target) {
            return true;
        }
        return false;
    }
};
// @lc code=end

