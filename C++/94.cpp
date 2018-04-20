#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
        // 模拟栈
        vector<int> stack;
        vector<int> res;

        if(root == NULL) {
            return stack;
        }

        TreeNode *lrt = root;
        TreeNode *rrt = root;

        // 遍历右子树
        rrt = rrt -> right;
        while(rrt -> left != NULL) {
            if(rrt -> right != NULL) {
                stack.push_back(rrt -> right -> val);
            }
            stack.push_back(rrt -> val);
            rrt = rrt -> left;
        }

        // 遍历左子树
        while(lrt -> left != NULL) {
            if(lrt -> right != NULL) {
                stack.push_back(lrt -> right -> val);
            }
            stack.push_back(lrt -> val);
            lrt = lrt -> left;
        }

        for(int i = stack.size()-1; i >= 1; i--) {
            res.push_back(stack[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int tree_val;

    cin >> tree_val;

    TreeNode *root = new TreeNode(tree_val);

    
}