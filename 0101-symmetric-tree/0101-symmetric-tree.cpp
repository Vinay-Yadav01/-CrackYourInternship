/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool solve(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        bool outCheck = solve(left->left, right->right);
        bool inCheck = solve(left->right, right->left);
        bool currentCheck = left->val == right->val;
        return outCheck && inCheck && currentCheck;
    }

public:
    bool isSymmetric(TreeNode* root) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return true;
        return solve(root->left, root->right);
    }
};