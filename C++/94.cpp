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

    vector<int> opt;

    void _inorder(TreeNode* root) {
        if(root != NULL) {
            if(root -> left != NULL) _inorder(root -> left);
            opt.push_back(root -> val);
            if(root -> right != NULL) _inorder(root -> right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        _inorder(root);
        return opt;
    }
};