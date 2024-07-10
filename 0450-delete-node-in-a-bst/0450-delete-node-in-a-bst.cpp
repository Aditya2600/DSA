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
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* ios(TreeNode* root){
        TreeNode* suc = root->right;
        while(suc->left){
            suc = suc->left;
        }
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if(root->left == NULL && root->right == NULL) return NULL;
            if(root->left == NULL || root->right == NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }
            if(root->left != NULL && root->right != NULL){
                TreeNode* suc = ios(root);
                root->val = suc->val;
                root->right = deleteNode(root->right,suc->val);
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};