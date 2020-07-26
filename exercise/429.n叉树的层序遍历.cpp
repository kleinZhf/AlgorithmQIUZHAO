/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;

        while (!q.empty()) {
            int k = q.size();
            vector<int> tmp;

            while (k--) {
                Node *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);

                for (const auto &node : cur->children) {
                    q.push(node);
                }
            }

            res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

