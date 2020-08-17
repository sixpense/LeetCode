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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;

        }
        
        return buildTreeNode(preorder, 0, n - 1, inorder, 0, n - 1);
    }

private:
    unordered_map<int, int> inMap;

    TreeNode* buildTreeNode(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[preorder[preStart]];

        int numsLeft = inRoot - inStart;

        root->left = buildTreeNode(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1);
        root->right = buildTreeNode(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot+1, inEnd);
        return root;

    }
};
