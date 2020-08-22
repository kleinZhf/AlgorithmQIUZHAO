#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<string>
#include<unordered_set>

using namespace std;


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

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<vector<int>>> dp(m, 
        vector<vector<int>>(n, vector<int>(n, INT_MIN)));

        int res = INT_MIN;

        for (int lcol = 0; lcol < n; ++lcol) {
            for (int rcol = lcol; rcol < n; ++rcol) {
                for (int row = 0; row < m; ++row) {
                    int cur = matrix[row][rcol] - (lcol ? matrix[row][lcol - 1] : 0);
                    if (cur > k) continue;

                    if (lcol == 0 && rcol == 2) {
                        cout << lcol << ' ' << rcol << ' ' << row << ' ' << cur << endl;
                    }

                    dp[row][lcol][rcol] = cur;

                    if (row && dp[row - 1][lcol][rcol] >= 0 && cur + dp[row - 1][lcol][rcol] <= k) {
                        dp[row][lcol][rcol] += dp[row - 1][lcol][rcol];
                    }

                    res = max(res, dp[row][lcol][rcol]);
                }
            }
        }

        return res;
    }
};

int main(void) {
    vector<vector<int>> matrix{
        {5, -4, -3, 4},
        {-3, -4, 4, 5},
        {5, 1, 5, -4}
    };

    int k = 8;

    cout << Solution().maxSumSubmatrix(matrix, k) << endl;
    
    return 0;
}