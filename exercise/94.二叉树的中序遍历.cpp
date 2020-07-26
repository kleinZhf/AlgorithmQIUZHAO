/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<TreeNode*> S;

        while (root || !S.empty()) {
            while (root) {
                S.push(root);
                root = root->left;
            }

            root = S.top();
            S.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    }
};
// @lc code=end

