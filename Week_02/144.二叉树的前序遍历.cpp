/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> S;
        S.push(root);
        vector<int> res;

        while (!S.empty()) {
            TreeNode *tmp = S.top();
            S.pop();
            res.push_back(tmp->val);

            if (tmp->right) S.push(tmp->right);
            if (tmp->left) S.push(tmp->left);
        }

        return res;
    }
};
// @lc code=end

