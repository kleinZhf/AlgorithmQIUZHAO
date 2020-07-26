/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (const auto &c : s) {
            switch (c) {
                case '(' :
                st.push(c);
                break;

                case '{' :
                st.push(c);
                break;

                case '[' :
                st.push(c);
                break;

                case ')' :
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                else {
                    st.pop();
                }
                break;

                case '}' :
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                else {
                    st.pop();
                }
                break;

                case ']' :
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                else {
                    st.pop();
                }
                break;
            }
        }

        return st.empty();
    }
};
// @lc code=end

