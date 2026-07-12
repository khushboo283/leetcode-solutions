/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetricTree(TreeNode* left,TreeNode* right){
        if(left==NULL||right==NULL){
            return left==right;
        }

        bool isLeftSame=isSymmetricTree(left->left,right->right);
        bool isRightSame=isSymmetricTree(left->right,right->left);

        return isLeftSame && isRightSame && (left->val==right->val);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;

        return isSymmetricTree(root->left,root->right);
    }
};