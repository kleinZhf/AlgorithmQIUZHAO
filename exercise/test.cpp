#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>


using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                if (!valid1(s[i - 1])) return 0;
                dp[i] = dp[i - 1];
            }
            else {
                if (valid1(s[i - 1])) {
                    cout << "---" << endl;
                    cout << dp[i - 1] << ' ' << i << ' ' << valid2(s[i]) << endl;
                    dp[i] = dp[i - 1] + (valid2(s[i]) ? (i == 1 ? 1 : dp[i - 2]) : 0);
                    cout << dp[i] << endl;
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
        }

        return dp[n - 1];
    }
private:
    bool valid1(char c) {
        if (c >= '1' && c <= '2') return true;
        return false;
    }

    bool valid2(char c) {
        if (c >= '0' && c <= '6') return true;
        return false;
    }
};

int main(void) {
    string s = "12";
    cout << Solution().numDecodings(s) << endl;
    return 0;
}
