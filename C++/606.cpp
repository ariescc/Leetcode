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
    string tree2str(TreeNode* t) {
        // 输出结果
        string res = "";

        if(t == NULL) {
            return res;
        }
        else {
            if(t -> left == NULL && t -> right == NULL) {
                return to_string(t -> val);
            }
            else if(t -> left != NULL && t -> right == NULL) {
                return to_string(t -> val) + "(" + tree2str(t -> left) + ")";
            }
            else if(t -> left == NULL && t -> right != NULL) {
                return to_string(t -> val) + "()" + "(" + tree2str(t -> right) + ")";
            }
            else {
                return to_string(t -> val) + "(" + tree2str(t -> left) + ")" + "(" + tree2str(t -> right) + ")";
            }
        }

    }   
};