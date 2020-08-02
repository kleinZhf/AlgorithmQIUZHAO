/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
// class Solution {
// public:
//     double myPow(double x, long long n) {
//         if (n == 0) return 1.0;
//         if (x == 1) return 1.0;

//         if (n < 0) {
//             x = 1.0 / x;
//             n = -n;
//         }

//         double halfPow = myPow(x, n / 2);
//         return halfPow * halfPow * (n % 2 ? x : 1.0);
//     }
// };

class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) return 1.0;
        if (x == 1) return 1.0;

        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }

        double res = 1.0;

        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }

        return res;
    }
};
// @lc code=end

