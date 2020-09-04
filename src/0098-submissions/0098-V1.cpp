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
    bool isBSTUnit(TreeNode* root, long long min, long long max) {
        if(root == nullptr) {
            return true;
        }
        if(root->val <= min || root->val >= max) {
            return false;
        }
        return isBSTUnit(root->left, min, root->val) && isBSTUnit(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return isBSTUnit(root, LONG_MIN, LONG_MAX);
    }

};
