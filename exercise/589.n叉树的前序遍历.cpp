/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        dfs(root);
        return res;
    }
private:
    vector<int> res;
    void dfs(Node *node) {
        if (!node) return;

        res.push_back(node->val);

        for (const auto &n : node->children) {
            dfs(n);
        }
    }
};
// @lc code=end

