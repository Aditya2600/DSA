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
    bool pathSum(TreeNode* root, int targetSum){
        if(root == NULL){
            return false;
        }
        if(root -> left == NULL && root -> right == NULL){
            return targetSum == root -> val;
        }
        bool leftAns = pathSum(root -> left, targetSum - root -> val);
        bool rightAns = pathSum(root -> right, targetSum - root -> val);
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root, targetSum); 
    }
};